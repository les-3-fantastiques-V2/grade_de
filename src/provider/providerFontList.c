/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerFontList.c
*/

#include "gradeDe.h"

static void _addFont(int fontId, FontList_t **fontList)
{
    Font_t *font = createFontById(fontId);

    if (font == NULL) return;

    FontList_t *newFontList = malloc(sizeof(FontList_t));
    newFontList->font = font;
    newFontList->next = *fontList;
    *fontList = newFontList;
}

void initFontListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    FontList_t *fontList = NULL;

    for (int i = 0; i < FONT_MAX; i++) {
        _addFont(i, &fontList);
    }

    gradeDe->fontList = fontList;
}

void destroyFontListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    while (gradeDe->fontList != NULL) {
        FontList_t *fontStruct = gradeDe->fontList;
        gradeDe->fontList = gradeDe->fontList->next;
        destroyFont(fontStruct->font); free(fontStruct);
    }
}
