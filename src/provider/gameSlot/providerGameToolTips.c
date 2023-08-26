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

    gameTooltips->originBackgroundPosition = (sfVector2f){0, 0};
    gameTooltips->background = createRectangleShape(
        (sfVector2f){250, 250},
        sfColor_fromRGB(200, 200, 200),
        gameTooltips->originBackgroundPosition
    );


    gameTooltips->originNamePosition = (sfVector2f){0, 0};
    gameTooltips->name = createTextWithMaxWidth(
        name,
        gameTooltips->originNamePosition,
        30,
        FONT_COMFORTAA_BOLD,
        250
    );
    sfFloatRect nameRect = sfText_getGlobalBounds(gameTooltips->name);

    gameTooltips->originDescriptionPosition = (sfVector2f){0, nameRect.height + 12};
    gameTooltips->description = createTextWithMaxWidth(
        description,
        gameTooltips->originDescriptionPosition,
        20,
        FONT_COMFORTAA_LIGHT,
        250
    );

    return gameTooltips;
}

void renderTooltips(GameTooltips_t *gameTooltips)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(windowConfig->window);
    sfVector2f origineBackgroundPosition = gameTooltips->originBackgroundPosition;
    sfVector2f origineNamePosition = gameTooltips->originNamePosition;
    sfVector2f origineDescriptionPosition = gameTooltips->originDescriptionPosition;
    sfVector2f newBackgroundPosition = (sfVector2f){
        mousePosition.x + origineBackgroundPosition.x,
        mousePosition.y + origineBackgroundPosition.y
    };
    sfVector2f newNamePosition = (sfVector2f){
        mousePosition.x + origineNamePosition.x,
        mousePosition.y + origineNamePosition.y
    };
    sfVector2f newDescriptionPosition = (sfVector2f){
        mousePosition.x + origineDescriptionPosition.x,
        mousePosition.y + origineDescriptionPosition.y
    };

    sfRectangleShape_setPosition(gameTooltips->background, newBackgroundPosition);
    sfText_setPosition(gameTooltips->name, newNamePosition);
    sfText_setPosition(gameTooltips->description, newDescriptionPosition);

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
