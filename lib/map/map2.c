/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** map2.c
*/

#include "map.h"

void freeMap(map_t *this)
{
    this->clear(this);
}

void freeMallocMap(map_t *this)
{
    if (this)
        this->clear(this);
    free(this);
}

int length(map_t *this)
{
    return this->size;
}

void *popBack(map_t *this)
{
    node_t *prec = this->head;
    node_t *curr = this->head->next;

    for (; curr->next != NULL; curr = curr->next)
        prec = curr;
    void *data = curr->data;
    prec->next = NULL;
    free(curr);
    return data;
}

void *popFront(map_t *this)
{
    node_t *tmp = this->head;
    void *data = tmp->data;

    this->head = tmp->next;
    free(tmp);
    return data;
}
