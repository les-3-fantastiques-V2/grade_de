/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerMouseCursor.c
*/

#include "gradeDe.h"

void renderMouseCursor(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    WindowConfig_t *windowConfig = gradeDe->windowConfig;
    sfVector2i mousePos = sfMouse_getPositionRenderWindow(windowConfig->window);
    sfVector2f cursorPos = (sfVector2f){mousePos.x, mousePos.y};

    if (gradeDe->mouseCursor->type == CURSOR_TYPE_HINT) {
        sfFloatRect cursorRect = sfSprite_getGlobalBounds(gradeDe->mouseCursor->currentCursor->cursor);
        cursorPos.x -= cursorRect.width;
        cursorPos.y -= cursorRect.height;
    } else if (gradeDe->mouseCursor->type == CURSOR_TYPE_CENTER){
        sfFloatRect cursorRect = sfSprite_getGlobalBounds(gradeDe->mouseCursor->currentCursor->cursor);
        cursorPos.x -= cursorRect.width / 2;
        cursorPos.y -= cursorRect.height / 2;
    }

    sfSprite_setPosition(gradeDe->mouseCursor->currentCursor->cursor, cursorPos);
    sfRenderWindow_drawSprite(windowConfig->window, gradeDe->mouseCursor->currentCursor->cursor, NULL);
}

void initMouseCursorStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    gradeDe->mouseCursor = malloc(sizeof(MouseCursor_t));
    initCursorListStruct();
    gradeDe->mouseCursor->currentCursor = getCursorById(CURSOR_DEFAULT);
    gradeDe->mouseCursor->type = true;
}

void destroyMouseCursorStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    destroyCursorListStruct();
    free(gradeDe->mouseCursor);
}

void changeMouseCursor(CURSOR_E cursorId, CURSOR_TYPE_E type)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    gradeDe->mouseCursor->currentCursor = getCursorById(cursorId);
    gradeDe->mouseCursor->type = type;
}
