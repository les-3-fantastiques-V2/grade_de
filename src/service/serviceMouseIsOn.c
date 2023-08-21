/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceMouseIsOn.c
*/

#include "gradeDe.h"

bool mouseIsOn(sfVector2f position, sfVector2f size)
{
    sfVector2i mousePosition = sfMouse_getPositionRenderWindow(
        getWindowConfigStruct()->window);

    if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
        mousePosition.y >= position.y && mousePosition.y <= position.y + size.y)
        return true;
    return false;
}
