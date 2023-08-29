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

    gameTooltips->originBackgroundPosition = (sfVector2f){10, 10};
    gameTooltips->background = createRectangleShape(
        (sfVector2f){250, 250},
        sfColor_fromRGB(200, 200, 200),
        gameTooltips->originBackgroundPosition
    );
    gameTooltips->backgroundTexture = sfTexture_createFromFile("assets/image/BoxLargeCream.png", NULL);
    sfRectangleShape_setTexture(gameTooltips->background, gameTooltips->backgroundTexture, sfTrue);

    gameTooltips->originNamePosition = (sfVector2f){
        gameTooltips->originBackgroundPosition.x + 10,
        gameTooltips->originBackgroundPosition.y + 10
    };
    gameTooltips->name = createTextWithMaxWidth(
        name,
        gameTooltips->originNamePosition,
        30,
        FONT_COMFORTAA_BOLD,
        230
    );
    sfFloatRect nameRect = sfText_getGlobalBounds(gameTooltips->name);

    gameTooltips->originDescriptionPosition = (sfVector2f){
        gameTooltips->originBackgroundPosition.x + 10,
        gameTooltips->originBackgroundPosition.y + 10 + nameRect.height + 12
    };
    gameTooltips->description = createTextWithMaxWidth(
        description,
        gameTooltips->originDescriptionPosition,
        20,
        FONT_COMFORTAA_LIGHT,
        230
    );

    return gameTooltips;
}

void destroyGameTooltips(GameTooltips_t *gameTooltips)
{
    sfRectangleShape_destroy(gameTooltips->background);
    sfText_destroy(gameTooltips->name);
    sfText_destroy(gameTooltips->description);
    free(gameTooltips);
}

void renderTooltips(GameTooltips_t *gameTooltips)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(windowConfig->window);
    int id = getGameSlotPositionIdByMousePosition();
    sfVector2f correction = {0, 0};
    if (id == 2 || id == 5) correction.x = -270;
    if (id == 3 || id == 4 || id == 5) correction.y = -270;

    sfVector2f origineBackgroundPosition = gameTooltips->originBackgroundPosition;
    sfVector2f newBackgroundPosition = (sfVector2f){
        mousePosition.x + origineBackgroundPosition.x + correction.x,
        mousePosition.y + origineBackgroundPosition.y + correction.y
    };

    sfVector2f origineNamePosition = gameTooltips->originNamePosition;
    sfVector2f newNamePosition = (sfVector2f){
        newBackgroundPosition.x + origineNamePosition.x,
        newBackgroundPosition.y + origineNamePosition.y
    };

    sfVector2f origineDescriptionPosition = gameTooltips->originDescriptionPosition;
    sfVector2f newDescriptionPosition = (sfVector2f){
        newBackgroundPosition.x + origineDescriptionPosition.x,
        newBackgroundPosition.y + origineDescriptionPosition.y
    };

    sfRectangleShape_setPosition(gameTooltips->background, newBackgroundPosition);
    sfText_setPosition(gameTooltips->name, newNamePosition);
    sfText_setPosition(gameTooltips->description, newDescriptionPosition);

    renderRectangleShape(gameTooltips->background);
    renderText(gameTooltips->name);
    renderText(gameTooltips->description);
}
