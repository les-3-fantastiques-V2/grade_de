/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerFont.c
*/

#include "gradeDe.h"

char *fontNameList[FONT_MAX] = {
    "ComfortaaBold",
    "ComfortaaLight",
    "ComfortaaRegular",
    "SpicyPizza",
};

void destroyFont(Font_t *font)
{
    sfFont_destroy(font->font);
    free(font);
}

Font_t *createFontById(FONT_E fontId)
{
    Font_t *font = malloc(sizeof(Font_t));
    char *fontPath = malloc(sizeof(char) * (strlen("assets/font/") + strlen(fontNameList[fontId]) + strlen(".ttf") + 1));

    if (font == NULL || fontPath == NULL) return NULL;
    strcpy(fontPath, "assets/font/");
    strcat(fontPath, fontNameList[fontId]);
    strcat(fontPath, ".ttf");

    font->fontId = fontId;
    font->font = sfFont_createFromFile(fontPath);

    free(fontPath);
    if (font->font == NULL) return NULL;
    return font;
}

sfFont *getFontById(FONT_E fontId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    FontList_t *fontList = gradeDe->fontList;

    if (fontId < 0 || fontId > FONT_MAX) return NULL;
    while (fontList != NULL) {
        if (fontList->font->fontId == fontId)
            return fontList->font->font;
        fontList = fontList->next;
    }
    return NULL;
}
