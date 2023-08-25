/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceRenderCircleShape.c
*/

#include "gradeDe.h"

void renderText(sfText *text)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawText(windowConfig->window, text, NULL);
}
