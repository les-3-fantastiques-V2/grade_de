/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerButton.c
*/

#include "gradeDe.h"

/* Action */
bool clickOnButton(Button_t *button)
{
    return (hoverButton(button) && sfMouse_isButtonPressed(sfMouseLeft));
}

bool hoverButton(Button_t *button)
{
    sfFloatRect buttonRect = sfRectangleShape_getGlobalBounds(button->button);

    return mouseIsOn(
        (sfVector2f) {buttonRect.left, buttonRect.top},
        (sfVector2f) {buttonRect.width, buttonRect.height}
    );
}

void setButtonStateAuto(Button_t *button)
{
    if (hoverButton(button))
        button->state = BUTTON_STATE_HOVER;
    else if (clickOnButton(button))
        button->state = BUTTON_STATE_ACTIVE;
    else
        button->state = BUTTON_STATE_DEFAULT;
}


/* Create */
Button_t *createButton(sfVector2f size, char *texturePath, sfVector2f position)
{
    Button_t *button = malloc(sizeof(Button_t));

    button->button = createRectangleShape(size, sfWhite, position);
    button->texture = sfTexture_createFromFile(texturePath, NULL);
    sfRectangleShape_setTexture(button->button, button->texture, sfTrue);
    button->state = BUTTON_STATE_DEFAULT;
    return button;
}


/* Render */
void renderButton(Button_t *button)
{
    setButtonStateAuto(button);

    if (button->state == BUTTON_STATE_HOVER)
        sfRectangleShape_setFillColor(button->button, (sfColor){255, 255, 255, 175});
    else
        sfRectangleShape_setFillColor(button->button, (sfColor){255, 255, 255, 255});

    renderRectangleShape(button->button);
}


/* Destroy */
void destroyButton(Button_t *button)
{
    sfRectangleShape_destroy(button->button);
    sfTexture_destroy(button->texture);
    free(button);
}
