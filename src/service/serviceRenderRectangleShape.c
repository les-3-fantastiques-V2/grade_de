/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceDrawRectangleShape.c
*/

#include "gradeDe.h"

void renderRectangleShape(sfRectangleShape *rectangleShape)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawRectangleShape(windowConfig->window, rectangleShape, NULL);
}
