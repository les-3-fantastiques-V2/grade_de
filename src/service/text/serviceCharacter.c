/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceCharacter.c
*/

#include "gradeDe.h"

bool charIsAlphabetic(char character)
{
    if (character >= 'A' && character <= 'Z') return true;
    if (character >= 'a' && character <= 'z') return true;
    return false;
}

bool charIsNumeric(char character)
{
    if (character >= '0' && character <= '9') return true;
    return false;
}

bool charIsAlphanumeric(char character)
{
    if (charIsAlphabetic(character)) return true;
    if (charIsNumeric(character)) return true;
    return false;
}
