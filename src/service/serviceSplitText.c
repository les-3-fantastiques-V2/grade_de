/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceSplitText.c
*/

#include "gradeDe.h"

static char *_mergeCharToString(char *string, char c)
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

char *splitText(char *text, int maxWidth, int fontSize)
{
    int maxLetterNumber = maxWidth / (fontSize / 1.4);

    char *newText = malloc(sizeof(char) * 1); newText[0] = '\0';
    int currentLetterText = 0; int countLetter = 0;
    while (text[currentLetterText] != '\0') {
        if (countLetter == maxLetterNumber) {
            newText = _mergeCharToString(newText, '\n');
            countLetter = 0;
            continue;
        }
        newText = _mergeCharToString(newText, text[currentLetterText]);
        countLetter++; currentLetterText++;
    }

    return newText;
}
