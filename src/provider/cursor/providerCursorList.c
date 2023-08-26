/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerCursorList.c
*/

#include "gradeDe.h"

static void _addCursor(CURSOR_E cursorId, CursorList_t **CursorList)
{
    Cursor_t *cursor = createCursorById(cursorId);

    if (cursor == NULL) return;

    CursorList_t *newCursorList = malloc(sizeof(CursorList_t));
    newCursorList->cursor = cursor;
    newCursorList->next = *CursorList;
    *CursorList = newCursorList;
}

void initCursorListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    CursorList_t *cursorList = NULL;

    for (int i = 0; i < CURSOR_MAX; i++) _addCursor(i, &cursorList);

    gradeDe->mouseCursor->cursorList = cursorList;
}

void destroyCursorListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    while (gradeDe->mouseCursor->cursorList != NULL) {
        CursorList_t *cursorStruct = gradeDe->mouseCursor->cursorList;
        gradeDe->mouseCursor->cursorList = gradeDe->mouseCursor->cursorList->next;
        destroyCursor(cursorStruct->cursor); free(cursorStruct);
    }
}
