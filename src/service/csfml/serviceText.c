/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceText.c
*/

#include "gradeDe.h"

static int _getCharacterWidth(int character, int fontSize, FONT_E fontId)
{
    sfFont *font = getFontById(fontId);
    sfGlyph glyph = sfFont_getGlyph(font, character, fontSize, sfFalse, 0);

    return glyph.advance;
}

static char *_splitWord(char *newText, char *word, int maxWidth, int currentWidth, int fontSize, FONT_E fontId)
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

static char *_splitText(char *text, int maxWidth, int fontSize, FONT_E fontId)
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


void renderText(sfText *text)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    sfRenderWindow_drawText(windowConfig->window, text, NULL);
}

sfText *createText(char *textContent, sfVector2f textPosition, unsigned int fontSize, FONT_E fontId)
{
    sfText *text = sfText_create();
    sfFont *font = getFontById(fontId);
    if (text == NULL || font == NULL) return NULL;

    sfText_setString(text, textContent);
    sfText_setPosition(text, textPosition);
    sfText_setColor(text, sfBlack);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, fontSize);
    return text;
}

sfText *createTextWithMaxWidth(char *textContent, sfVector2f textPosition, unsigned int fontSize, FONT_E fontId, int maxWidth)
{
    char *splittedText = _splitText(textContent, maxWidth, fontSize, fontId);
    sfText *text = createText(splittedText, textPosition, fontSize, fontId);
    free(splittedText);
    return text;
}

void renderTextWithAllCallbacks(sfText *text, void (*callbackPressed)(void), void (*callbackHover)(void), void (*callbackDefault)(void))
{
    sfFloatRect rect = sfText_getGlobalBounds(text);
    sfVector2f pos = {rect.left, rect.top};
    sfVector2f size = {rect.width, rect.height};
    if (mouseIsOn(pos, size) && sfMouse_isButtonPressed(sfMouseLeft)) {
        callbackPressed();
    } else if (mouseIsOn(pos, size)) {
        callbackHover();
    } else {
        callbackDefault();
    }

    renderText(text);
}