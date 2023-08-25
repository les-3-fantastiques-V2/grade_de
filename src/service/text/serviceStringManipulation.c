/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceMergeToString.c
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

static int *_getTableConfig(char *string)
{
    int *tableConfig = malloc(sizeof(int) * 2);
    tableConfig[0] = 0; tableConfig[1] = 0;
    int currentWidth = 0;

    for(int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '\n' || string[i] == '\t' || string[i] == ' ') {
            tableConfig[0] = (tableConfig[0] < currentWidth) ? currentWidth : tableConfig[0];
            tableConfig[1]++; currentWidth = 0;
        } else {
            currentWidth++;
        }
    }
    tableConfig[0] = (tableConfig[0] < currentWidth) ? currentWidth : tableConfig[0];
    tableConfig[1]++; currentWidth = 0;

    return tableConfig;
}

bool isAlphanumeric(char character)
{
    if (character >= '0' && character <= '9') return true;
    if (character >= 'A' && character <= 'Z') return true;
    if (character >= 'a' && character <= 'z') return true;
    return false;
}

char **stringToWordArray(char *string)
{
    int *tableConfig = _getTableConfig(string);
    char **table = malloc(sizeof(char *) * (tableConfig[1] + 1));
    for (int i = 0; i < tableConfig[1]; i++)
        table[i] = malloc(sizeof(char) * (tableConfig[0] + 1));
    for (int i = 0; i < tableConfig[1]; i++)
        for (int j = 0; j < tableConfig[0]; j++)
            table[i][j] = '\0';
    table[tableConfig[1]] = NULL;

    int i = 0; int j = 0; int k = 0;
    while (string[k] != '\0') {
        if (string[k] == '\n' || string[k] == '\t' || string[k] == ' ') {
            table[i][j] = '\0'; i++; j = 0; k++;
        } else {
            table[i][j] = string[k]; j++; k++;
        }
    }

    for (i = 0; table[i] != NULL; i++)
        for (j = 0; table[i][j] != '\0'; j++)
            if (!isAlphanumeric(table[i][j])) table[i][j] = '\0';

    free(tableConfig);
    return table;
}
