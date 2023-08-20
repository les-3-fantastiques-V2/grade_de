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
        sfDefaultStyle,
        NULL
    );

    gradeDeStruct->windowConfig = windowConfigStruct;
}

void destroyWindowConfigStruct(void)
{
    WindowConfig_t *windowConfigStruct = getWindowConfigStruct();

    sfRenderWindow_destroy(windowConfigStruct->window);
}
