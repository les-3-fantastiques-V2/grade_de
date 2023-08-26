/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** cursor.h
*/

#ifndef CURSOR_H_
    #define CURSOR_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== ENUM ====================*/


    typedef enum CURSOR {
        CURSOR_DEFAULT,
        CURSOR_INFO,
        CURSOR_EXIT,
        CURSOR_MAX,
    } CURSOR_E;

    typedef enum CURSOR_TYPE {
        CURSOR_TYPE_HINT,
        CURSOR_TYPE_POINTER,
        CURSOR_TYPE_CENTER,
    } CURSOR_TYPE_E;


/*==================== STRUCTURE =====================*/


    typedef struct structCursor {
        CURSOR_E cursorId;
        sfSprite *cursor;
        sfTexture *texture;
    } Cursor_t;

    typedef struct structCursorList {
        Cursor_t *cursor;
        struct structCursorList *next;
    } CursorList_t;

    typedef struct structMouseCursor {
        CURSOR_TYPE_E type;
        CursorList_t *cursorList;
        Cursor_t *currentCursor;
    } MouseCursor_t;


/*==================== FUNCTION ====================*/


        // Cursor
            void destroyCursor(Cursor_t *cursor);
            Cursor_t *getCursorById(CURSOR_E cursorId);
            Cursor_t *createCursorById(CURSOR_E cursorId);

        // Cursor List
            void initCursorListStruct(void);
            void destroyCursorListStruct(void);

        // Mouse Cursor
            void renderMouseCursor(void);
            void initMouseCursorStruct(void);
            void destroyMouseCursorStruct(void);
            void changeMouseCursor(CURSOR_E cursorId, CURSOR_TYPE_E type);


/*==================== MACRO ====================*/


#endif /*CURSOR_H_*/