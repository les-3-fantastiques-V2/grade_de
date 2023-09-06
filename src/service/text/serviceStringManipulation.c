/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceStringManipulation.c
*/

#include "gradeDe.h"

char *mergeCharToString(char *string, char c)
{
    int stringLength = strlen(string);
    char *newString = malloc(sizeof(char) * (stringLength + 2));

    for (int i = 0; i < stringLength; i++)
        newString[i] = string[i];
    newString[stringLength] = c;
    newString[stringLength + 1] = '\0';

    free(string);
    return newString;
}

char *mergeStringToString(char *string1, char *string2)
{
    int string1Length = strlen(string1);
    int string2Length = strlen(string2);
    char *newString = malloc(sizeof(char) * (string1Length + string2Length + 1));

    for (int i = 0; i < string1Length; i++)
        newString[i] = string1[i];
    for (int i = 0; i < string2Length; i++)
        newString[string1Length + i] = string2[i];
    newString[string1Length + string2Length] = '\0';

    free(string1);
    return newString;
}

static int _countWords(char *string, char *separator)
{
    int words = 0;

    int i = 0;
    for (; string[i] != '\0'; i++)
        if (charIsInString(string[i], separator))
            words++;
    if (i > 0 && !charIsInString(string[i - 1], separator))
        words++;

    return words;
}

static int _getWordLength(char *string, char *separator, int index)
{
    int length = 0;

    for (int i = index; string[i] != '\0' && !charIsInString(string[i], separator); i++)
        length++;

    return length;
}

char **stringToWordArray(char *string, char *separator)
{
    int words = _countWords(string, separator);
    char **array = malloc(sizeof(char *) * (words + 1));

    int index = 0;
    for (int i = 0; i < words; i++) {
        int length = _getWordLength(string, separator, index);
        array[i] = malloc(sizeof(char) * (length + 1));
        for (int j = 0; j < length; j++) array[i][j] = string[index + j];
        array[i][length] = '\0';
        index += length + 1;
    }

    array[words] = NULL;
    return array;
}
