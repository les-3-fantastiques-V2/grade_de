/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerToggleButton.c
*/

#include "gradeDe.h"

/* Action */

bool hoverToggleButton(ToggleButton_t *toggleButton)
{
    sfFloatRect buttonRect = sfRectangleShape_getGlobalBounds(toggleButton->button);

    return mouseIsOn(
        (sfVector2f) {buttonRect.left, buttonRect.top},
        (sfVector2f) {buttonRect.width, buttonRect.height}
    );
}

bool clickOnToggleButton(ToggleButton_t *toggleButton)
{
    WindowConfig_t *windowConfig = getWindowConfigStruct();

    if (hoverToggleButton(toggleButton) && windowConfig->event.type == sfEvtMouseButtonReleased) {
        playSound(SOUND_BUTTON_PRESSED);
        windowConfig->event.type = -1;
        toggleButton->isToggled = !toggleButton->isToggled;
        return true;
    }
    return false;
}

/* Render */

void renderToggleButton(ToggleButton_t *toggleButton)
{
    renderRectangleShape(toggleButton->button);
    if (toggleButton->isToggled) renderRectangleShape(toggleButton->toggle);
}


/* Create */

ToggleButton_t *createToggleButton(sfVector2f size, sfVector2f position)
{
    ToggleButton_t *toggleButton = malloc(sizeof(ToggleButton_t));

    toggleButton->button = createRectangleShape(size, sfWhite, position);
    toggleButton->textureButton = sfTexture_createFromFile("assets/image/IconSquare.png", NULL);
    sfRectangleShape_setTexture(toggleButton->button, toggleButton->textureButton, sfTrue);

    position.x += 8; position.y += 8; size.x -= 16; size.y -= 16;
    toggleButton->toggle = createRectangleShape(size, sfWhite, position);
    toggleButton->textureToggle = sfTexture_createFromFile("assets/image/IconCheck.png", NULL);
    sfRectangleShape_setTexture(toggleButton->toggle, toggleButton->textureToggle, sfTrue);
    toggleButton->isToggled = false;

    return toggleButton;
}


/* Destroy */

void destroyToggleButton(ToggleButton_t *toggleButton)
{
    sfRectangleShape_destroy(toggleButton->button);
    sfTexture_destroy(toggleButton->textureButton);
    sfRectangleShape_destroy(toggleButton->toggle);
    sfTexture_destroy(toggleButton->textureToggle);
    free(toggleButton);
}
