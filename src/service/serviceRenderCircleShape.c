/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceRenderCircleShape.c
*/

#include "gradeDe.h"

void renderCircleShape(sfCircleShape *circleShape)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawCircleShape(windowConfig->window, circleShape, NULL);
}
