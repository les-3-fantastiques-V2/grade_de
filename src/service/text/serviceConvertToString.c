/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceConvertToString.c
*/

#include "gradeDe.h"

static int _getCharacterNumber(int number)
{
    int character = (number > 0) ? 0 : 1;
    number = (number > 0) ? number : -number;

    while (number > 0) {
        number /= 10;
        character++;
    }
    return (character);
}

char *intToString(int number)
{
    if (number == 0) {
        char *str = malloc(sizeof(char) * 2);
        strcpy(str, "0");
        return (str);
    }

    int character = _getCharacterNumber(number);
    char *str = malloc(sizeof(char) * (character + 1));

    if (number < 0) str[0] = '-';
    int index = (number > 0) ? 0 : 1;
    for (; number > 0; index++) {
        str[index] = (number % 10) + '0';
        number /= 10;
    }
    str[index] = '\0';
    index--;

    for (int i = 0; i < index; i++, index--) {
        char temp = str[i];
        str[i] = str[index];
        str[index] = temp;
    }

    return (str);
}
