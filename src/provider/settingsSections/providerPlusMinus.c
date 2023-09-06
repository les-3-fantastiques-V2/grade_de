/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerPlusMinus.c
*/

#include "gradeDe.h"

static void _centerValueText(PlusMinus_t *plusMinus)
{
    sfVector2f plusPosition = sfRectangleShape_getPosition(plusMinus->plus->button);
    sfFloatRect plusRect = sfRectangleShape_getGlobalBounds(plusMinus->plus->button);
    sfVector2f minusPosition = sfRectangleShape_getPosition(plusMinus->minus->button);
    sfFloatRect textRect = sfText_getGlobalBounds(plusMinus->valueText);

    sfVector2f newTextPosition = {
        (plusPosition.x + plusRect.width + minusPosition.x) / 2 - textRect.width / 2,
        plusPosition.y - (plusRect.height / 2 - textRect.height / 2),
    };

    sfText_setPosition(plusMinus->valueText, newTextPosition);
}

static void _modValue(PlusMinus_t *plusMinus, int value)
{
    if (value > 0) {
        if (plusMinus->value + plusMinus->step <= plusMinus->maxValue) {
            plusMinus->value += plusMinus->step;
        }
    } else {
        if (plusMinus->value - plusMinus->step >= plusMinus->minValue) {
            plusMinus->value -= plusMinus->step;
        }
    }

    char *valueStr = intToString(plusMinus->value);
    sfText_setString(plusMinus->valueText, valueStr);
    _centerValueText(plusMinus);
}

static void _clickOnButton(Button_t *button, PlusMinus_t *plusMinus, int value)
{
    if (hoverButton(button) && sfMouse_isButtonPressed(sfMouseLeft)) {
        if (getTime(plusMinus->clickCooldown) < 0.1) return;
        _modValue(plusMinus, value);
        plusMinus->update();
        resetTime(plusMinus->clickCooldown);
    }
}


void renderPlusMinus(PlusMinus_t *plusMinus)
{
    renderText(plusMinus->title);
    renderText(plusMinus->valueText);
    _clickOnButton(plusMinus->plus, plusMinus, 1);
    _clickOnButton(plusMinus->minus, plusMinus, -1);
    if (plusMinus->value + plusMinus->step <= plusMinus->maxValue) renderButton(plusMinus->plus);
    if (plusMinus->value - plusMinus->step >= plusMinus->minValue) renderButton(plusMinus->minus);
}

PlusMinus_t *initPlusMinusStruct(char *title, int *values, sfVector2f position, void (*update)(void))
{
    PlusMinus_t *plusMinus = malloc(sizeof(PlusMinus_t));

    char *initialValueStr = intToString(values[0]);
    plusMinus->value = values[PLUS_MINUS_VALUE];
    plusMinus->minValue = values[PLUS_MINUS_MIN];
    plusMinus->maxValue = values[PLUS_MINUS_MAX];
    plusMinus->step = values[PLUS_MINUS_STEP];
    plusMinus->title = createText(title, (sfVector2f){position.x, position.y}, 40, FONT_SPICY_PIZZA);
    plusMinus->plus = createButton((sfVector2f){30, 40}, "assets/image/IconRight.png", (sfVector2f){WINDOW_WIDTH - percent(WINDOW_WIDTH, 5) - 50, position.y});
    plusMinus->minus = createButton((sfVector2f){30, 40}, "assets/image/IconLeft.png", (sfVector2f){WINDOW_WIDTH - percent(WINDOW_WIDTH, 5) - 380, position.y});
    plusMinus->valueText = createText(initialValueStr, (sfVector2f){0, 0}, 40, FONT_SPICY_PIZZA);
    plusMinus->update = update;
    plusMinus->clickCooldown = sfClock_create();
    _centerValueText(plusMinus);

    return (plusMinus);
}

void destroyPlusMinus(PlusMinus_t *plusMinus)
{
    sfClock_destroy(plusMinus->clickCooldown);
    sfText_destroy(plusMinus->title);
    sfText_destroy(plusMinus->valueText);
    destroyButton(plusMinus->plus);
    destroyButton(plusMinus->minus);
    free(plusMinus);
}
