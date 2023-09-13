/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerTransition.c
*/

#include "gradeDe.h"

Transition_t *getTransitionStruct(void)
{
    static Transition_t transition;
    return &transition;
}

void initTransitionStruct(void)
{
    Transition_t *transition = getTransitionStruct();

    transition->transitionRectangle = createRectangleShape(
        (sfVector2f){WINDOW_WIDTH, WINDOW_HEIGHT},
        sfBlack,
        (sfVector2f){0, 0}
    );
    transition->transitionClock = sfClock_create();
    transition->opacity = 0;
    transition->nextScene = EXIT;
    transition->transitionState = TRANSITION_STATE_NONE;
}

void destroyTransitionStruct(void)
{
    Transition_t *transition = getTransitionStruct();

    sfRectangleShape_destroy(transition->transitionRectangle);
    sfClock_destroy(transition->transitionClock);
}
