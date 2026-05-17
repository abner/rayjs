/*******************************************************************************************
*
*   raylib [core] example - input gamepad
*
*   NOTE: This example requires a Gamepad connected to the system
*         raylib is configured to work with the following gamepads:
*                - Xbox 360 Controller (Xbox 360, Xbox One)
*                - PLAYSTATION(R)3 Controller
*         Check raylib.h for buttons configuration
*
*   JavaScript port for rayjs — uses JS string methods instead of raylib Text* functions
*
********************************************************************************************/

const XBOX_ALIAS_1 = "xbox";
const XBOX_ALIAS_2 = "x-box";
const PS_ALIAS_1   = "playstation";
const PS_ALIAS_2   = "sony";

// Initialization
//--------------------------------------------------------------------------------------
const screenWidth = 800;
const screenHeight = 450;

setConfigFlags(FLAG_MSAA_4X_HINT);
initWindow(screenWidth, screenHeight, "raylib [core] example - input gamepad");

const texPs3Pad  = loadTexture("resources/ps3.png");
const texXboxPad = loadTexture("resources/xbox.png");

// Axis deadzones
const leftStickDeadzoneX  = 0.1;
const leftStickDeadzoneY  = 0.1;
const rightStickDeadzoneX = 0.1;
const rightStickDeadzoneY = 0.1;
const leftTriggerDeadzone  = -0.9;
const rightTriggerDeadzone = -0.9;

setTargetFPS(60);
//--------------------------------------------------------------------------------------

let gamepad = 0;

// Main game loop
while (!windowShouldClose())
{
    // Update
    //----------------------------------------------------------------------------------
    if (isKeyPressed(KEY_LEFT)  && gamepad > 0) gamepad--;
    if (isKeyPressed(KEY_RIGHT)) gamepad++;

    const mousePosition = getMousePosition();
    const vibrateButton = new Rectangle(10, 70.0 + 20*getGamepadAxisCount(gamepad) + 20, 75, 24);

    if (isMouseButtonPressed(MOUSE_BUTTON_LEFT) && checkCollisionPointRec(mousePosition, vibrateButton))
        setGamepadVibration(gamepad, 1.0, 1.0, 1.0);
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    beginDrawing();

        clearBackground(RAYWHITE);

        if (isGamepadAvailable(gamepad))
        {
            const name = getGamepadName(gamepad);
            drawText(`GP${gamepad}: ${name}`, 10, 10, 10, BLACK);

            // Get axis values
            let leftStickX  = getGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_X);
            let leftStickY  = getGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_Y);
            let rightStickX = getGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_X);
            let rightStickY = getGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_Y);
            let leftTrigger  = getGamepadAxisMovement(gamepad, GAMEPAD_AXIS_LEFT_TRIGGER);
            let rightTrigger = getGamepadAxisMovement(gamepad, GAMEPAD_AXIS_RIGHT_TRIGGER);

            // Apply deadzones
            if (leftStickX  > -leftStickDeadzoneX  && leftStickX  < leftStickDeadzoneX)  leftStickX  = 0.0;
            if (leftStickY  > -leftStickDeadzoneY  && leftStickY  < leftStickDeadzoneY)  leftStickY  = 0.0;
            if (rightStickX > -rightStickDeadzoneX && rightStickX < rightStickDeadzoneX) rightStickX = 0.0;
            if (rightStickY > -rightStickDeadzoneY && rightStickY < rightStickDeadzoneY) rightStickY = 0.0;
            if (leftTrigger  < leftTriggerDeadzone)  leftTrigger  = -1.0;
            if (rightTrigger < rightTriggerDeadzone) rightTrigger = -1.0;

            const nameLower = name.toLowerCase();

            if (nameLower.includes(XBOX_ALIAS_1) || nameLower.includes(XBOX_ALIAS_2))
            {
                drawTexture(texXboxPad, 0, 0, DARKGRAY);

                // Xbox home
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) drawCircle(394, 89, 19, RED);

                // Basic buttons
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT))     drawCircle(436, 150, 9, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT))      drawCircle(352, 150, 9, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))  drawCircle(501, 151, 15, BLUE);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))  drawCircle(536, 187, 15, LIME);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) drawCircle(572, 151, 15, MAROON);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP))    drawCircle(536, 115, 15, GOLD);

                // D-pad
                drawRectangle(317, 202, 19, 71, BLACK);
                drawRectangle(293, 228, 69, 19, BLACK);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP))    drawRectangle(317, 202, 19, 26, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN))  drawRectangle(317, 247, 19, 26, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT))  drawRectangle(292, 228, 25, 19, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) drawRectangle(336, 228, 26, 19, RED);

                // Bumpers
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1))  drawCircle(259, 61, 20, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) drawCircle(536, 61, 20, RED);

                // Left joystick
                const leftColor = isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB) ? RED : BLACK;
                drawCircle(259, 152, 39, BLACK);
                drawCircle(259, 152, 34, LIGHTGRAY);
                drawCircle(259 + Math.trunc(leftStickX*20), 152 + Math.trunc(leftStickY*20), 25, leftColor);

                // Right joystick
                const rightColor = isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB) ? RED : BLACK;
                drawCircle(461, 237, 38, BLACK);
                drawCircle(461, 237, 33, LIGHTGRAY);
                drawCircle(461 + Math.trunc(rightStickX*20), 237 + Math.trunc(rightStickY*20), 25, rightColor);

                // Triggers
                drawRectangle(170, 30, 15, 70, GRAY);
                drawRectangle(604, 30, 15, 70, GRAY);
                drawRectangle(170, 30, 15, Math.trunc(((1 + leftTrigger)/2)*70),  RED);
                drawRectangle(604, 30, 15, Math.trunc(((1 + rightTrigger)/2)*70), RED);
            }
            else if (nameLower.includes(PS_ALIAS_1) || nameLower.includes(PS_ALIAS_2))
            {
                drawTexture(texPs3Pad, 0, 0, DARKGRAY);

                // PS button
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE)) drawCircle(396, 222, 13, RED);

                // Basic buttons
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT))      drawRectangle(328, 170, 32, 13, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT))     drawTriangle(new Vector2(436, 168), new Vector2(436, 185), new Vector2(464, 177), RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP))    drawCircle(557, 144, 13, LIME);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) drawCircle(586, 173, 13, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))  drawCircle(557, 203, 13, VIOLET);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))  drawCircle(527, 173, 13, PINK);

                // D-pad
                drawRectangle(225, 132, 24, 84, BLACK);
                drawRectangle(195, 161, 84, 25, BLACK);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP))    drawRectangle(225, 132, 24, 29, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN))  drawRectangle(225, 186, 24, 30, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT))  drawRectangle(195, 161, 30, 25, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) drawRectangle(249, 161, 30, 25, RED);

                // Bumpers
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1))  drawCircle(239, 82, 20, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) drawCircle(557, 82, 20, RED);

                // Left joystick
                const leftColor = isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB) ? RED : BLACK;
                drawCircle(319, 255, 35, BLACK);
                drawCircle(319, 255, 31, LIGHTGRAY);
                drawCircle(319 + Math.trunc(leftStickX*20), 255 + Math.trunc(leftStickY*20), 25, leftColor);

                // Right joystick
                const rightColor = isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB) ? RED : BLACK;
                drawCircle(475, 255, 35, BLACK);
                drawCircle(475, 255, 31, LIGHTGRAY);
                drawCircle(475 + Math.trunc(rightStickX*20), 255 + Math.trunc(rightStickY*20), 25, rightColor);

                // Triggers
                drawRectangle(169, 48, 15, 70, GRAY);
                drawRectangle(611, 48, 15, 70, GRAY);
                drawRectangle(169, 48, 15, Math.trunc(((1 + leftTrigger)/2)*70),  RED);
                drawRectangle(611, 48, 15, Math.trunc(((1 + rightTrigger)/2)*70), RED);
            }
            else
            {
                // Generic gamepad layout
                drawRectangleRounded(new Rectangle(175, 110, 460, 220), 0.3, 16, DARKGRAY);

                // Basic buttons
                drawCircle(365, 170, 12, RAYWHITE);
                drawCircle(405, 170, 12, RAYWHITE);
                drawCircle(445, 170, 12, RAYWHITE);
                drawCircle(516, 191, 17, RAYWHITE);
                drawCircle(551, 227, 17, RAYWHITE);
                drawCircle(587, 191, 17, RAYWHITE);
                drawCircle(551, 155, 17, RAYWHITE);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_LEFT))      drawCircle(365, 170, 10, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE))           drawCircle(405, 170, 10, GREEN);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_MIDDLE_RIGHT))     drawCircle(445, 170, 10, BLUE);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_LEFT))  drawCircle(516, 191, 15, GOLD);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))  drawCircle(551, 227, 15, BLUE);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) drawCircle(587, 191, 15, GREEN);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_FACE_UP))    drawCircle(551, 155, 15, RED);

                // D-pad
                drawRectangle(245, 145, 28, 88, RAYWHITE);
                drawRectangle(215, 174, 88, 29, RAYWHITE);
                drawRectangle(247, 147, 24, 84, BLACK);
                drawRectangle(217, 176, 84, 25, BLACK);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_UP))    drawRectangle(247, 147, 24, 29, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_DOWN))  drawRectangle(247, 201, 24, 30, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_LEFT))  drawRectangle(217, 176, 30, 25, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) drawRectangle(271, 176, 30, 25, RED);

                // Bumpers
                drawRectangleRounded(new Rectangle(215, 98, 100, 10), 0.5, 16, DARKGRAY);
                drawRectangleRounded(new Rectangle(495, 98, 100, 10), 0.5, 16, DARKGRAY);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_TRIGGER_1))  drawRectangleRounded(new Rectangle(215, 98, 100, 10), 0.5, 16, RED);
                if (isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) drawRectangleRounded(new Rectangle(495, 98, 100, 10), 0.5, 16, RED);

                // Left joystick
                const leftColor = isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_LEFT_THUMB) ? RED : BLACK;
                drawCircle(345, 260, 40, BLACK);
                drawCircle(345, 260, 35, LIGHTGRAY);
                drawCircle(345 + Math.trunc(leftStickX*20), 260 + Math.trunc(leftStickY*20), 25, leftColor);

                // Right joystick
                const rightColor = isGamepadButtonDown(gamepad, GAMEPAD_BUTTON_RIGHT_THUMB) ? RED : BLACK;
                drawCircle(465, 260, 40, BLACK);
                drawCircle(465, 260, 35, LIGHTGRAY);
                drawCircle(465 + Math.trunc(rightStickX*20), 260 + Math.trunc(rightStickY*20), 25, rightColor);

                // Triggers
                drawRectangle(151, 110, 15, 70, GRAY);
                drawRectangle(644, 110, 15, 70, GRAY);
                drawRectangle(151, 110, 15, Math.trunc(((1 + leftTrigger)/2)*70),  RED);
                drawRectangle(644, 110, 15, Math.trunc(((1 + rightTrigger)/2)*70), RED);
            }

            drawText(`DETECTED AXIS [${getGamepadAxisCount(gamepad)}]:`, 10, 50, 10, MAROON);

            for (let i = 0; i < getGamepadAxisCount(gamepad); i++)
            {
                drawText(`AXIS ${i}: ${getGamepadAxisMovement(gamepad, i).toFixed(2)}`, 20, 70 + 20*i, 10, DARKGRAY);
            }

            // Vibrate button
            drawRectangleRec(vibrateButton, SKYBLUE);
            drawText("VIBRATE", Math.trunc(vibrateButton.x + 14), Math.trunc(vibrateButton.y + 1), 10, DARKGRAY);

            const pressed = getGamepadButtonPressed();
            if (pressed !== GAMEPAD_BUTTON_UNKNOWN)
                drawText(`DETECTED BUTTON: ${pressed}`, 10, 430, 10, RED);
            else
                drawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY);
        }
        else
        {
            drawText(`GP${gamepad}: NOT DETECTED`, 10, 10, 10, GRAY);
            drawTexture(texXboxPad, 0, 0, LIGHTGRAY);
        }

    endDrawing();
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
unloadTexture(texPs3Pad);
unloadTexture(texXboxPad);
closeWindow();
//--------------------------------------------------------------------------------------
