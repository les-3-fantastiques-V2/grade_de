/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceSplitText.c
*/

#include "gradeDe.h"

static int _getCharacterWidth(int character, int fontSize, int fontId)
{
    sfFont *font = getFontById(fontId);
    sfGlyph glyph = sfFont_getGlyph(font, character, fontSize, sfFalse, 0);

    return glyph.advance;
}

static char *_splitWord(char *newText, char *word, int maxWidth, int currentWidth, int fontSize, int fontId)
{
    for (int i = 0; word[i] != '\0'; i++) {
        int characterWidth = _getCharacterWidth(word[i], fontSize, fontId);
        currentWidth += characterWidth;
        if ( currentWidth >= maxWidth) {
            newText = mergeStringToString(newText, "\n");
            currentWidth = characterWidth;
        }
        newText = mergeCharToString(newText, word[i]);
    }

    return newText;
}

char *splitText(char *text, int maxWidth, int fontSize, int fontId)
{
    char *newText = malloc(sizeof(char) * 1); newText[0] = '\0';
    char **words = stringToWordArray(text);
    int currentWidth = 0;

    for (int wordIndex = 0; words[wordIndex] != NULL; wordIndex++) {
        int wordWidth = 0;
        for (int i = 0; words[wordIndex][i] != '\0'; i++) wordWidth += _getCharacterWidth(words[wordIndex][i], fontSize, fontId);
        if (wordWidth > maxWidth) {
            newText = _splitWord(newText, words[wordIndex], maxWidth, currentWidth, fontSize, fontId);
            continue;
        }
        if (wordWidth + currentWidth > maxWidth) {
            newText = mergeStringToString(newText, "\n");
            currentWidth = 0;
        }
        newText = mergeStringToString(newText, words[wordIndex]);
        newText = mergeStringToString(newText, " ");
        currentWidth += wordWidth + _getCharacterWidth(' ', fontSize, fontId);
    }

    for (int i = 0; words[i] != NULL; i++) free(words[i]);

    return newText;
}
