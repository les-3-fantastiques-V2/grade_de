/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceCreateCircleShape.c
*/

#include "gradeDe.h"

sfCircleShape *createCircleShape(float radius, sfColor color, sfVector2f position)
{
    sfCircleShape *circleShape = sfCircleShape_create();

    sfCircleShape_setRadius(circleShape, radius);
    sfCircleShape_setFillColor(circleShape, color);
    sfCircleShape_setPosition(circleShape, position);
    return circleShape;
}
