/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** font.h
*/

#ifndef FONT_H_
    #define FONT_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== STRUCTURE =====================*/


    typedef struct structFont {
        int fontId;
        sfFont *font;
    } Font_t;

    typedef struct structFontList {
        Font_t *font;
        struct structFontList *next;
    } FontList_t;


/*==================== ENUM ====================*/


    enum FONT {
        FONT_COMFORTAA_BOLD,
        FONT_COMFORTAA_LIGHT,
        FONT_COMFORTAA_REGULAR,
        FONT_SPICY_PIZZA,
        FONT_MAX,
    };


/*==================== FUNCTION ====================*/


/*==================== MACRO ====================*/


#endif /*FONT_H_*/