/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** button.h
*/

#ifndef BUTTON_H_
    #define BUTTON_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    typedef struct structButtonCircle {
        sfCircleShape *hitbox;
        sfTexture *texture;
    } ButtonCircle_t;


/*==================== FUNCTION ====================*/


    // Button Circle
        void renderButtonCircle(ButtonCircle_t *buttonCircle);
        bool mouseIsOnCircleButton(ButtonCircle_t *buttonCircle);
        void destroyButtonCircleColor(ButtonCircle_t *buttonCircle);
        void destroyButtonCircleTexture(ButtonCircle_t *buttonCircle);
        ButtonCircle_t *createButtonCircleColor(float radius, sfColor color, sfVector2f position);
        ButtonCircle_t *createButtonCircleTexture(float radius, sfTexture *texture, sfVector2f position);


/*==================== MACRO ====================*/


#endif /*BUTTON_H_*/