/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** controllerTransitionManager.c
*/

#include "gradeDe.h"

static void _setTransitionOpacity(void)
{
    Transition_t *transition = getTransitionStruct();

    sfRectangleShape_setFillColor(
        transition->transitionRectangle,
        (sfColor){0, 0, 0, transition->opacity}
    );
}

static void _updateTransition(void)
{
    Transition_t *transition = getTransitionStruct();
    float time = getTime(transition->transitionClock);
    if (transition->transitionState == TRANSITION_STATE_OUT && transition->opacity >= 255 && time < 0.3) return;
    if (time < 0.02) return;

    transition->opacity += 10 * transition->transitionState;
    _setTransitionOpacity();
    resetTime(transition->transitionClock);

    if (transition->transitionState == TRANSITION_STATE_IN && transition->opacity >= 255) {
        transition->opacity = 255; _setTransitionOpacity();
        transition->transitionState = TRANSITION_STATE_OUT;
        changeScene(transition->nextScene);
    } else if (transition->transitionState == TRANSITION_STATE_OUT && transition->opacity <= 0) {
        transition->opacity = 0; _setTransitionOpacity();
        transition->transitionState = TRANSITION_STATE_NONE;
    }
}


void renderTransition(void)
{
    Transition_t *transition = getTransitionStruct();
    if (transition->transitionState == TRANSITION_STATE_NONE) return;

    WindowConfig_t *windowConfig = getWindowConfigStruct();

    _updateTransition();
    sfRenderWindow_drawRectangleShape(windowConfig->window, transition->transitionRectangle, NULL);
}

void playTransition(SCENE_E nextScene)
{
    Transition_t *transition = getTransitionStruct();
    if (transition->transitionState != TRANSITION_STATE_NONE) return;

    transition->opacity = 0;
    _setTransitionOpacity();
    resetTime(transition->transitionClock);

    transition->nextScene = nextScene;
    transition->transitionState = TRANSITION_STATE_IN;
}
