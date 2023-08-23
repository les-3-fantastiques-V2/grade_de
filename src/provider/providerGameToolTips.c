/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerGameToolTips.c
*/

#include "gradeDe.h"

GameTooltips_t *createGameTooltips(char *name, char *description)
{
    GameTooltips_t *gameTooltips = malloc(sizeof(GameTooltips_t));

    gameTooltips->name = createText(name, (sfVector2f){0, 0}, 30, FONT_COMFORTAA_BOLD);
    gameTooltips->description = createText(description, (sfVector2f){0, 40}, 20, FONT_COMFORTAA_LIGHT);
    gameTooltips->background = createRectangleShape(
        (sfVector2f){250, 250},
        sfColor_fromRGB(200, 200, 200),
        (sfVector2f){0, 0}
    );

    return gameTooltips;
}

void renderTooltips(GameTooltips_t *gameTooltips)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(windowConfig->window);
    sfVector2f firstPosition = (sfVector2f){mousePosition.x + 10, mousePosition.y + 10};
    sfVector2f secondPosition = (sfVector2f){firstPosition.x, firstPosition.y + 40};

    sfRectangleShape_setPosition(gameTooltips->background, firstPosition);
    sfText_setPosition(gameTooltips->name, firstPosition);
    sfText_setPosition(gameTooltips->description, secondPosition);

    renderRectangleShape(gameTooltips->background);
    renderText(gameTooltips->name);
    renderText(gameTooltips->description);
}

void destroyGameTooltips(GameTooltips_t *gameTooltips)
{
    sfRectangleShape_destroy(gameTooltips->background);
    sfText_destroy(gameTooltips->name);
    sfText_destroy(gameTooltips->description);
    free(gameTooltips);
}
