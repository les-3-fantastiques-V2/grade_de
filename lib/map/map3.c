/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** map3.c
*/

#include "map.h"

void *get(map_t *this, char *key)
{
    node_t *tmp = this->head;

    while (tmp != NULL) {
        if (strcmp(tmp->key, key) == 0)
            return tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}

static void initMap(map_t *this)
{
    this->pushFront = &pushFront;
    this->pushBack = &pushBack;
    this->remove = &removeNode;
    this->clear = &clear;
    this->view = &view;
    this->length = &length;
    this->popBack = &popBack;
    this->popFront = &popFront;
    this->get = &get;
    this->size = 0;
    this->head = NULL;
}

map_t createMap(void)
{
    map_t this;

    this.free = &freeMap;
    initMap(&this);
    return this;
}

map_t *createMallocMap(void)
{
    map_t *this = malloc(sizeof(map_t));

    this->free = &freeMallocMap;
    initMap(this);
    return this;
}
