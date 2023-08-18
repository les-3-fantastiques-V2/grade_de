/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** main.c
*/

#include "runner.h"

int main(void)
{
    map_t *textures = loadAssets("runner");
    for (node_t *curr = textures->head; curr != NULL; curr = curr->next)
        printf("%s\n", curr->key);
    destroyAssets(textures);
    return 0;
}
