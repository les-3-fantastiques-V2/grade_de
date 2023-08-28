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

    gradeDeStruct->windowConfig = windowConfigStruct;
}

void destroyWindowConfigStruct(void)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    sfRenderWindow_destroy(windowConfigStruct->window);
}