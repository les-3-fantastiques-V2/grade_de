/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceCirlcleShape.c
*/

#include "gradeDe.h"

void renderCircleShape(sfCircleShape *circleShape)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawCircleShape(windowConfig->window, circleShape, NULL);
}

sfCircleShape *createCircleShape(float radius, sfColor color, sfVector2f position)
{
    sfCircleShape *circleShape = sfCircleShape_create();

    sfCircleShape_setRadius(circleShape, radius);
    sfCircleShape_setFillColor(circleShape, color);
    sfCircleShape_setPosition(circleShape, position);
    return circleShape;
}
