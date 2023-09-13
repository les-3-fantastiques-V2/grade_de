/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** WindowConfigProvider.c
*/

#include "gradeDe.h"

WindowConfig_t *getWindowConfigStruct(void)
{
    static WindowConfig_t windowConfigStruct;
    return &windowConfigStruct;
}

void setBrightness(int brightness)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    windowConfigStruct->brightness = brightness;
    sfRectangleShape_setFillColor(
        windowConfigStruct->brightnessRectangle,
        (sfColor){0, 0, 0, 255 - percent(255, windowConfigStruct->brightness)}
    );
    char *brightnessString = intToString(windowConfigStruct->brightness);
    setConfig("brightness", brightnessString);
    free(brightnessString);
}

void setFrameRate(int frameRate)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    windowConfigStruct->frameRate = frameRate;
    sfRenderWindow_setFramerateLimit(windowConfigStruct->window, windowConfigStruct->frameRate);
    char *frameRateString = intToString(windowConfigStruct->frameRate);
    setConfig("frameRate", frameRateString);
    free(frameRateString);
}

void initWindowConfigStruct(void)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    windowConfigStruct->videoMode = (sfVideoMode){WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    windowConfigStruct->name = "GradeDe";
    char *frameRate = getConfigValueByName("frameRate");
    if (frameRate != NULL) {
        int frameRateValue = (int)atof(frameRate);
        windowConfigStruct->frameRate = frameRateValue;
    } else {
        setConfig("frameRate", "60");
        windowConfigStruct->frameRate = 60;
    }
    windowConfigStruct->window = sfRenderWindow_create(
        windowConfigStruct->videoMode,
        windowConfigStruct->name,
        sfTitlebar | sfClose,
        NULL
    );
    sfVideoMode desktopVideoMode = sfVideoMode_getDesktopMode();
    sfVector2i newPosition = {
        desktopVideoMode.width / 2 - WINDOW_WIDTH / 2,
        desktopVideoMode.height / 2 - WINDOW_HEIGHT / 2
    };
    sfRenderWindow_setPosition(windowConfigStruct->window, newPosition);
    sfRenderWindow_setMouseCursorVisible(windowConfigStruct->window, sfFalse);

    char *brightness = getConfigValueByName("brightness");
    if (brightness != NULL) {
        int brightnessValue = (int)atof(brightness);
        windowConfigStruct->brightness = brightnessValue;
    } else {
        setConfig("brightness", "100");
        windowConfigStruct->brightness = 100;
    }
    windowConfigStruct->brightnessRectangle = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor){0, 0, 0, 255 - percent(255, windowConfigStruct->brightness)},
        (sfVector2f){0, 0}
    );
}

void destroyWindowConfigStruct(void)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    sfRectangleShape_destroy(windowConfigStruct->brightnessRectangle);
    sfRenderWindow_destroy(windowConfigStruct->window);
}
