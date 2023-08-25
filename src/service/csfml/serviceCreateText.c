/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceCreateText.c
*/

#include "gradeDe.h"

sfText *createText(char *textContent, sfVector2f textposition, unsigned int fontSize, int fontId)
{
    sfText *text = sfText_create();
    sfFont *font = getFontById(fontId);
    if (text == NULL || font == NULL) return NULL;

    sfText_setString(text, textContent);
    sfText_setPosition(text, textposition);
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, fontSize);
    return text;
}
