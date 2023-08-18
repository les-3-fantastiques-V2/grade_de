/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerSceneChooseGame.c
*/

#include "gradeDe.h"

void _renderSceneMenuChooseGame(void)
{
}

void sceneMenuChooseGame(void)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    while (sceneIsOpen(SCENE_MENU_CHOOSE_GAME)) {
        eventManager();
        _renderSceneMenuChooseGame();
        sfRenderWindow_clear(windowConfig->window, sfBlack);
        sfRenderWindow_display(windowConfig->window);
    }
}
