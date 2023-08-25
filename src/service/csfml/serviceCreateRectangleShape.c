/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceCreateRectangleShape.c
*/

#include "gradeDe.h"

sfRectangleShape *createRectangleShape(sfVector2f size, sfColor color, sfVector2f position)
{
    sfRectangleShape *rectangleShape = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangleShape, size);
    sfRectangleShape_setFillColor(rectangleShape, color);
    sfRectangleShape_setPosition(rectangleShape, position);
    return rectangleShape;
}
