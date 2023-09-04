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
}

void initWindowConfigStruct(void)
{
    GradeDe_t *gradeDeStruct = getGradeDeStruct();
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    windowConfigStruct->videoMode = (sfVideoMode){WINDOW_WIDTH, WINDOW_HEIGHT, 32};
    windowConfigStruct->name = "GradeDe";
    windowConfigStruct->frameRate = 60;
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
    windowConfigStruct->brightness = 100;
    windowConfigStruct->brightnessRectangle = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        (sfColor){0, 0, 0, 255 - percent(255, windowConfigStruct->brightness)},
        (sfVector2f){0, 0}
    );

    gradeDeStruct->windowConfig = windowConfigStruct;
}

void destroyWindowConfigStruct(void)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    sfRectangleShape_destroy(windowConfigStruct->brightnessRectangle);
    sfRenderWindow_destroy(windowConfigStruct->window);
}
