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


    typedef enum BUTTON_STATE {
        BUTTON_STATE_DEFAULT,
        BUTTON_STATE_HOVER,
        BUTTON_STATE_ACTIVE
    } BUTTON_STATE_E;


/*==================== STRUCTURE =====================*/


    typedef struct structButton {
        sfRectangleShape *button;
        sfTexture *texture;
        BUTTON_STATE_E state;
    } Button_t;

    typedef struct structToggleButton {
        sfRectangleShape *button;
        sfTexture *textureButton;
        sfRectangleShape *toggle;
        sfTexture *textureToggle;
        bool isToggled;
    } ToggleButton_t;


/*==================== FUNCTION ====================*/

    // Button
        void renderButton(Button_t *button);
        void destroyButton(Button_t *button);
        void setButtonStateAuto(Button_t *button);

        bool hoverButton(Button_t *button);
        bool clickOnButton(Button_t *button, void (*callback)(void));

        Button_t *createButton(sfVector2f size, char *texturePath, sfVector2f position);

    // ToggleButton
        void renderToggleButton(ToggleButton_t *toggleButton);
        void destroyToggleButton(ToggleButton_t *toggleButton);

        bool hoverToggleButton(ToggleButton_t *toggleButton);
        bool clickOnToggleButton(ToggleButton_t *toggleButton);

        ToggleButton_t *createToggleButton(sfVector2f size, sfVector2f position);


/*==================== MACRO ====================*/


#endif /*BUTTON_H_*/