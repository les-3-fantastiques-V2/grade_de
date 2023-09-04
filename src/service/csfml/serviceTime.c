/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceTimer.c
*/

#include "gradeDe.h"

void resetTime(sfClock *clock)
{
    sfClock_restart(clock);
}

float getTime(sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    return seconds;
}