/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** service.h
*/

#ifndef SERVICE_H_
    #define SERVICE_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include


/*==================== STRUCTURE =====================*/


/*==================== ENUM ====================*/


/*==================== FUNCTION ====================*/


    // CSFML
        // Circle Shape
            void renderCircleShape(sfCircleShape *circleShape);
            sfCircleShape *createCircleShape(float radius, sfColor color, sfVector2f position);

        // Mouse
            bool mouseIsOn(sfVector2f position, sfVector2f size);

        // Rectangle Shape
            void renderRectangleShape(sfRectangleShape *rectangleShape);
            sfRectangleShape *createRectangleShape(sfVector2f size, sfColor color, sfVector2f position);

        // Scene
            bool sceneIsOpen(int currentSceneId);

        // Text
            void renderText(sfText *text);
            sfText *createText(char *textContent, sfVector2f textPosition, unsigned int fontSize, int fontId);
            sfText *createTextWithMaxWidth(char *textContent, sfVector2f textPosition, unsigned int fontSize, int fontId, int maxWidth);

    // Math
        // Percent
            int percent(int value, int percent);

    // Text
        // Character
            bool charIsNumeric(char character);
            bool charIsAlphabetic(char character);
            bool charIsAlphanumeric(char character);

        // String Manipulation
            char *mergeCharToString(char *string, char c);
            char *mergeStringToString(char *string1, char *string2);
            char **stringToWordArray(char *string);


/*==================== MACRO ====================*/


#endif /*SERVICE_H_*/

