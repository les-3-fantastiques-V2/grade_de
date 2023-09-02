/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerCursor.c
*/

#include "gradeDe.h"

char *CursorNameList[CURSOR_MAX] = {
    "Default",
    "Info",
};

void destroyCursor(Cursor_t *cursor)
{
    sfSprite_destroy(cursor->cursor);
    sfTexture_destroy(cursor->texture);
    free(cursor);
}

Cursor_t *createCursorById(CURSOR_E cursorId)
{
    Cursor_t *cursor = malloc(sizeof(Cursor_t));
    char *cursorPath = malloc(sizeof(char) * (strlen("assets/cursor/") + strlen(CursorNameList[cursorId]) + strlen(".png") + 1));

    if (cursor == NULL || cursorPath == NULL) return NULL;
    strcpy(cursorPath, "assets/cursor/");
    strcat(cursorPath, CursorNameList[cursorId]);
    strcat(cursorPath, ".png");

    cursor->cursorId = cursorId;
    cursor->cursor = sfSprite_create();
    cursor->texture = sfTexture_createFromFile(cursorPath, NULL);
    sfSprite_setTexture(cursor->cursor, cursor->texture, sfTrue);
    sfSprite_setScale(cursor->cursor, (sfVector2f){0.2, 0.2});

    free(cursorPath);
    if (cursor->cursor == NULL || cursor->texture == NULL) return NULL;
    return cursor;
}

Cursor_t *getCursorById(CURSOR_E cursorId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    CursorList_t *cursorList = gradeDe->mouseCursor->cursorList;

    if (cursorId < 0 || cursorId > CURSOR_MAX) return NULL;
    while (cursorList != NULL) {
        if (cursorList->cursor->cursorId == cursorId)
            return cursorList->cursor;
        cursorList = cursorList->next;
    }

    return NULL;
}
