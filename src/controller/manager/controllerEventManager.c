/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerEventManager.c
*/

#include "gradeDe.h"

void eventManager(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    while (sfRenderWindow_pollEvent(windowConfig->window, &windowConfig->event)) {
        if (windowConfig->event.type == sfEvtClosed) gradeDe->currentSceneId = EXIT;
    }
}
