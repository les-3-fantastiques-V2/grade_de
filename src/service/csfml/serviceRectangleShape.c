/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceRectangleShape.c
*/

#include "gradeDe.h"

void renderRectangleShape(sfRectangleShape *rectangleShape)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawRectangleShape(windowConfig->window, rectangleShape, NULL);
}

sfRectangleShape *createRectangleShape(sfVector2f size, sfColor color, sfVector2f position)
{
    sfRectangleShape *rectangleShape = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangleShape, size);
    sfRectangleShape_setFillColor(rectangleShape, color);
    sfRectangleShape_setPosition(rectangleShape, position);
    return rectangleShape;
}
