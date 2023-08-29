/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerButton.c
*/

#include "gradeDe.h"

/* Create */
ButtonCircle_t *createButtonCircleColor(float radius, sfColor color, sfVector2f position)
{
    ButtonCircle_t *buttonCircle = malloc(sizeof(ButtonCircle_t));

    buttonCircle->hitbox = createCircleShape(radius, color, position);
    buttonCircle->texture = NULL;
    return buttonCircle;
}

ButtonCircle_t *createButtonCircleTexture(float radius, sfTexture *texture, sfVector2f position)
{
    ButtonCircle_t *buttonCircle = malloc(sizeof(ButtonCircle_t));

    buttonCircle->texture = texture;
    buttonCircle->hitbox = createCircleShape(radius, sfTransparent, position);
    sfCircleShape_setTexture(buttonCircle->hitbox, texture, sfTrue);
    return buttonCircle;
}


/* Render */
void renderButtonCircle(ButtonCircle_t *buttonCircle)
{
    renderCircleShape(buttonCircle->hitbox);
}


/* Destroy */
void destroyButtonCircleColor(ButtonCircle_t *buttonCircle)
{
    sfCircleShape_destroy(buttonCircle->hitbox);
    free(buttonCircle);
}

void destroyButtonCircleTexture(ButtonCircle_t *buttonCircle)
{
    sfCircleShape_destroy(buttonCircle->hitbox);
    sfTexture_destroy(buttonCircle->texture);
    free(buttonCircle);
}
