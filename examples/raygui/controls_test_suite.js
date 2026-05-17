// Initialization
//---------------------------------------------------------------------------------------
let screenWidth = 690;
let screenHeight = 560;

initWindow(screenWidth, screenHeight, "raygui - controls test suite");
setExitKey(0);

// GUI controls initialization
// raygui 5.0: mutable state is passed as out-param objects { fieldName: value }
//----------------------------------------------------------------------------------
let dropdownBox000Active = { active: 0 };
let dropDown000EditMode = false;

let dropdownBox001Active = { active: 0 };
let dropDown001EditMode = false;

let spinner001Value = { value: 0 };
let spinnerEditMode = false;

let valueBox002Value = { value: 0 };
let valueBoxEditMode = false;

let textBoxText = { text: "Text box" };
let textBoxEditMode = false;

let listViewScrollIndex = { scrollIndex: 0 };
let listViewActive = { active: -1 };

let comboBoxActive = { active: 1 };

let toggleGroupActive = { active: 0 };

let sliderValue = { value: 50 };
let sliderBarValue = { value: 60 };
let progressValue = { value: 0.4 };

let forceSquaredChecked = { checked: false };

let alphaValue = { alpha: 0.5 };

let viewScroll = new Vector2(0, 0);

// Re-enabled controls: struct pointer out-params
let pickerColor = new Color(255, 0, 120, 255);
let mouseGridCell = new Vector2(0, 0);
let scrollPanelScroll = new Vector2(0, 0);
let scrollPanelView = new Rectangle(0, 0, 0, 0);
let valueBoxFloatText = { textValue: "0.00" };
let valueBoxFloatValue = { value: 0.0 };
let valueBoxFloatEditMode = false;
//----------------------------------------------------------------------------------

let exitWindow = false;
let showMessageBox = false;

let textInput = { text: "" };
let showTextInputBox = false;

let textInputFileName = "";

setTargetFPS(60);
//--------------------------------------------------------------------------------------

// Main game loop
while (!exitWindow)
{
    // Update
    //----------------------------------------------------------------------------------
    exitWindow = windowShouldClose();

    if (isKeyPressed(KEY_ESCAPE)) showMessageBox = !showMessageBox;

    if (isKeyDown(KEY_LEFT_CONTROL) && isKeyPressed(KEY_S)) showTextInputBox = true;

    if (isFileDropped())
    {
        let droppedFiles = loadDroppedFiles();
        if ((droppedFiles.length > 0) && isFileExtension(droppedFiles[0], ".rgs")) guiLoadStyle(droppedFiles[0]);
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    beginDrawing();

        clearBackground(getColor(guiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (dropDown000EditMode || dropDown001EditMode) guiLock();

        // First GUI column
        guiCheckBox(new Rectangle(25, 108, 15, 15), "FORCE CHECK!", forceSquaredChecked);

        guiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
        if (guiSpinner(new Rectangle(25, 135, 125, 30), null, spinner001Value, 0, 100, spinnerEditMode)) spinnerEditMode = !spinnerEditMode;
        if (guiValueBox(new Rectangle(25, 175, 125, 30), null, valueBox002Value, 0, 100, valueBoxEditMode)) valueBoxEditMode = !valueBoxEditMode;
        guiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT);
        if (guiTextBox(new Rectangle(25, 215, 125, 30), textBoxText, textBoxEditMode)) textBoxEditMode = !textBoxEditMode;

        guiSetStyle(BUTTON, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);

        if (guiButton(new Rectangle(25, 255, 125, 30), guiIconText(ICON_FILE_SAVE, "Save File"))) showTextInputBox = true;

        guiGroupBox(new Rectangle(25, 310, 125, 150), "STATES");
        guiSetState(STATE_NORMAL);    if (guiButton(new Rectangle(30, 320, 115, 30), "NORMAL")) { }
        guiSetState(STATE_FOCUSED);   if (guiButton(new Rectangle(30, 355, 115, 30), "FOCUSED")) { }
        guiSetState(STATE_PRESSED);   if (guiButton(new Rectangle(30, 390, 115, 30), "#15#PRESSED")) { }
        guiSetState(STATE_DISABLED);  if (guiButton(new Rectangle(30, 425, 115, 30), "DISABLED")) { }
        guiSetState(STATE_NORMAL);

        guiComboBox(new Rectangle(25, 470, 125, 30), "ONE;TWO;THREE;FOUR", comboBoxActive);

        // GuiValueBoxFloat: float out-param via { textValue } + { value } objects
        if (guiValueBoxFloat(new Rectangle(25, 505, 125, 30), null, valueBoxFloatText, valueBoxFloatValue, valueBoxFloatEditMode)) valueBoxFloatEditMode = !valueBoxFloatEditMode;

        // NOTE: GuiDropdownBox must draw after any other control that can be covered on unfolding
        guiUnlock();
        guiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, TEXT_ALIGN_LEFT);
        if (guiDropdownBox(new Rectangle(25, 65, 125, 30), "#01#ONE;#02#TWO;#03#THREE;#04#FOUR", dropdownBox001Active, dropDown001EditMode)) dropDown001EditMode = !dropDown001EditMode;

        guiSetStyle(DROPDOWNBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
        if (guiDropdownBox(new Rectangle(25, 25, 125, 30), "ONE;TWO;THREE", dropdownBox000Active, dropDown000EditMode)) dropDown000EditMode = !dropDown000EditMode;

        // Second GUI column
        guiListView(new Rectangle(165, 25, 140, 140), "Charmander;Bulbasaur;#18#Squirtel;Pikachu;Eevee;Pidgey", listViewScrollIndex, listViewActive);

        // GuiGrid: Vector2* out-param — mouseCell updated in-place
        guiGrid(new Rectangle(165, 175, 140, 140), null, 20, 3, mouseGridCell);

        // GuiScrollPanel: Vector2* scroll + Rectangle* view updated in-place
        guiScrollPanel(new Rectangle(165, 325, 140, 65), null, new Rectangle(0, 0, 220, 180), scrollPanelScroll, scrollPanelView);

        guiToggleGroup(new Rectangle(165, 400, 140, 25), "#1#ONE\n#3#TWO\n#8#THREE\n#23#", toggleGroupActive);

        // Third GUI column
        guiPanel(new Rectangle(320, 25, 225, 140), "Panel Info");

        // GuiColorPicker: Color* updated in-place via opaque JS Color object
        guiColorPicker(new Rectangle(320, 170, 196, 192), null, pickerColor);

        guiSlider(new Rectangle(355, 400, 165, 20), "TEST", `${Math.floor(sliderValue.value)}`, sliderValue, -50, 100);
        guiSliderBar(new Rectangle(320, 430, 200, 20), null, `${Math.floor(sliderBarValue.value)}`, sliderBarValue, 0, 100);
        guiProgressBar(new Rectangle(320, 460, 200, 20), null, null, progressValue, 0, 1);

        guiStatusBar(new Rectangle(0, getScreenHeight() - 20, getScreenWidth(), 20), "This is a status bar");

        guiColorBarAlpha(new Rectangle(320, 490, 200, 30), null, alphaValue);

        if (showMessageBox)
        {
            drawRectangle(0, 0, getScreenWidth(), getScreenHeight(), fade(RAYWHITE, 0.8));
            let result = guiMessageBox(new Rectangle(getScreenWidth()/2 - 125, getScreenHeight()/2 - 50, 250, 100), guiIconText(ICON_EXIT, "Close Window"), "Do you really want to exit?", "Yes;No");

            if ((result == 0) || (result == 2)) showMessageBox = false;
            else if (result == 1) exitWindow = true;
        }

        if (showTextInputBox)
        {
            drawRectangle(0, 0, getScreenWidth(), getScreenHeight(), fade(RAYWHITE, 0.8));
            let result = guiTextInputBox(new Rectangle(getScreenWidth()/2 - 120, getScreenHeight()/2 - 60, 240, 140), "Save", guiIconText(ICON_FILE_SAVE, "Save file as..."), "Ok;Cancel", textInput, null);

            if (result == 1)
            {
                textInputFileName = textInput.text;
            }

            if ((result == 0) || (result == 1) || (result == 2))
            {
                showTextInputBox = false;
                textInput.text = "";
            }
        }
        //----------------------------------------------------------------------------------

    endDrawing();
    //----------------------------------------------------------------------------------
}

// De-Initialization
//--------------------------------------------------------------------------------------
closeWindow();
//--------------------------------------------------------------------------------------
