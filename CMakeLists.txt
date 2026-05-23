cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0063 NEW)
set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE STRING "" FORCE)

# Workaround for windows to prevent static linking of pthread
IF (WIN32)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static")
ENDIF()
if (UNIX)
	set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fPIC -DCONFIG_BIGNUM")
	set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -fPIC -DCONFIG_BIGNUM")
endif (UNIX)

project(rayjs LANGUAGES C)
#Inherit some compiler flags
include(CheckCCompilerFlag)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_C_STANDARD 11)
macro(xcheck_add_c_compiler_flag FLAG)
    string(REPLACE "-" "" FLAG_NO_HYPHEN ${FLAG})
    check_c_compiler_flag(${FLAG} COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
    if(COMPILER_SUPPORTS_${FLAG_NO_HYPHEN})
        add_compile_options(${FLAG})
    endif()
endmacro()

xcheck_add_c_compiler_flag(-Wno-implicit-fallthrough)
xcheck_add_c_compiler_flag(-Wno-sign-compare)
xcheck_add_c_compiler_flag(-Wno-missing-field-initializers)
xcheck_add_c_compiler_flag(-Wno-unused-parameter)
xcheck_add_c_compiler_flag(-Wno-unused-but-set-variable)
xcheck_add_c_compiler_flag(-Wno-array-bounds)
xcheck_add_c_compiler_flag(-Wno-format-truncation)
xcheck_add_c_compiler_flag(-funsigned-char)
#Inherit some compiler flags

include(CheckCCompilerFlag)
include(GNUInstallDirs)

set(CMAKE_C_VISIBILITY_PRESET hidden)

message("=== Configure mimalloc ===")
set(MI_BUILD_OBJECT OFF CACHE BOOL "Build object library" FORCE)
set(MI_BUILD_TESTS OFF CACHE BOOL "Build test executables" FORCE)
set(MI_BUILD_SHARED OFF CACHE BOOL "Build shared library" FORCE)
set(MI_WIN_REDIRECT OFF CACHE BOOL "Use redirection module on Windows" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/mimalloc EXCLUDE_FROM_ALL)

# Controls whether raylib/raygui/quickjs also use mimalloc for their allocators
option(RAYJS_USE_MIMALLOC "Use mimalloc allocators in raylib/raygui/quickjs overrides" OFF)

message("=== Configure QuickJS ===")
# add quickjs
set(quickjs_version 0.14.0)
set(quickjs_sources_root ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/quickjs)
# Patched quickjs.{c,h} are emitted into the build tree, NOT into the
# submodule, so `thirdparty/quickjs` stays pristine across configure/build
# cycles. The patched dir is prepended to the include path below so the
# unmodified submodule sources (libregexp.c, libunicode.c, …) still resolve
# `#include "quickjs.h"` to the patched header.
set(quickjs_patched_dir ${CMAKE_BINARY_DIR}/quickjs-patched)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/quickjs/quickjs.h ${quickjs_patched_dir}/quickjs.h @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/quickjs/quickjs.c ${quickjs_patched_dir}/quickjs.c @ONLY)
set(quickjs_sources
	${quickjs_patched_dir}/quickjs.h        # patched (build dir)
	${quickjs_patched_dir}/quickjs.c        # patched (build dir)
	${quickjs_sources_root}/quickjs-atom.h
	${quickjs_sources_root}/libregexp.c
	${quickjs_sources_root}/libunicode.c
	${quickjs_sources_root}/cutils.h
	${quickjs_sources_root}/dtoa.c
	${quickjs_sources_root}/gen/repl.c
	${quickjs_sources_root}/gen/standalone.c
)
add_library(quickjs STATIC
	${quickjs_sources}
)
target_compile_definitions(quickjs PRIVATE CONFIG_VERSION=${quickjs_version} )
if(RAYJS_USE_MIMALLOC)
	target_compile_definitions(quickjs PUBLIC QJS_USE_MIMALLOC )
	file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/variables/mimalloc.cmake" mimalloc.cmake)
	file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/variables/mimalloc.h" mimalloc.h)
	file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/variables/stb_mimalloc.h" stb_mimalloc.h)
	file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/variables/mimalloc_gui.h" mimalloc_gui.h)
	file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/variables/m3d_malloc.h" m3d_malloc.h)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/raylib/src/CMakeLists.txt ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/src/CMakeLists.txt @ONLY)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/raylib/src/raylib.h ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/src/raylib.h @ONLY)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/raylib/src/stb_truetype.h ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/src/external/stb_truetype.h @ONLY)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/raygui/src/raygui.h ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raygui/src/raygui.h @ONLY)
	configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/overrides/raylib/src/external/m3d.h ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/src/external/m3d.h @ONLY)
endif()
target_include_directories(quickjs PRIVATE ${quickjs_patched_dir} ${quickjs_sources_root})
target_link_libraries(quickjs)


add_library(lightmapper INTERFACE)
target_include_directories(lightmapper INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/lightmapper)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})


message("=== Configure raylib ===")
if(APPLE)
    # macOS supports OpenGL up to 4.1 only
    add_definitions(-DGRAPHICS_API_OPENGL_33)
else()
    add_definitions(-DGRAPHICS_API_OPENGL_43)
endif()
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib EXCLUDE_FROM_ALL)

message("=== Configure Box2D ===")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/box2d EXCLUDE_FROM_ALL)

message("=== Generate embedded lib/*.js modules ===")
set(JS_EXT_MODULES_H "${CMAKE_CURRENT_SOURCE_DIR}/src/js_ext_modules.h")
set(JS_EXT_TYPINGS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bindings/typings")
file(GLOB LIB_JS_FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.js")
file(GLOB LIB_DTS_FILES "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.d.ts")

# Generate at configure time so the header and typings exist before compilation.
execute_process(
    COMMAND ${CMAKE_COMMAND}
        -DLIB_DIR="${CMAKE_CURRENT_SOURCE_DIR}/lib"
        -DOUTPUT_FILE="${JS_EXT_MODULES_H}"
        -DTYPINGS_DIR="${JS_EXT_TYPINGS_DIR}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/gen_ext_modules.cmake"
)

message("=== Bind files together ===")
file(GLOB files src/*.c)
add_executable(${CMAKE_PROJECT_NAME} ${files})

# Re-generate when any lib/*.js or lib/*.d.ts file changes.
add_custom_command(
    OUTPUT ${JS_EXT_MODULES_H}
    COMMAND ${CMAKE_COMMAND}
        -DLIB_DIR="${CMAKE_CURRENT_SOURCE_DIR}/lib"
        -DOUTPUT_FILE="${JS_EXT_MODULES_H}"
        -DTYPINGS_DIR="${JS_EXT_TYPINGS_DIR}"
        -P "${CMAKE_CURRENT_SOURCE_DIR}/cmake/gen_ext_modules.cmake"
    DEPENDS ${LIB_JS_FILES} ${LIB_DTS_FILES}
    COMMENT "Re-embedding lib/*.js into src/js_ext_modules.h and updating typings"
)
add_custom_target(gen_ext_modules DEPENDS ${JS_EXT_MODULES_H})
add_dependencies(${CMAKE_PROJECT_NAME} gen_ext_modules)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raygui/src)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/examples/shaders)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/examples/others)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/examples/shapes)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/raylib/src/external/glfw/include)
if(APPLE)
    set_target_properties(${CMAKE_PROJECT_NAME}
        PROPERTIES
        COMPILE_DEFINITIONS GRAPHICS_API_OPENGL_33=1
    )
else()
    set_target_properties(${CMAKE_PROJECT_NAME}
        PROPERTIES
        COMPILE_DEFINITIONS GRAPHICS_API_OPENGL_43=1
    )
endif()
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${quickjs_patched_dir} ${quickjs_sources_root})
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE include)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE src)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/mimalloc/include)

set(RAYJS_LINK_LIBRARIES "quickjs" "mimalloc-static")
set(RAYJS_LINK_LIBRARIES "${RAYJS_LINK_LIBRARIES}" "raylib" "lightmapper" "box2d")
target_link_libraries(${CMAKE_PROJECT_NAME} ${RAYJS_LINK_LIBRARIES})

# Web (WebAssembly) target — included only under emscripten toolchain.
# Inert for native builds (clang/gcc never see EMSCRIPTEN set).
if(EMSCRIPTEN)
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/web.cmake)
endif()