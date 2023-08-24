/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** map1.c
*/

#include "map.h"

void pushFront(map_t *this, char *key, void *data, enum type type)
{
    node_t *new = malloc(sizeof(node_t));

    if (new == NULL)
        return;
    new->key = key;
    new->data = data;
    new->type = type;
    new->next = this->head;
    this->head = new;
    this->size++;
}

void pushBack(map_t *this, char *key, void *data, enum type type)
{
    node_t *new = malloc(sizeof(node_t));
    node_t *tmp = this->head;

    if (new == NULL)
        return;
    new->key = key;
    new->data = data;
    new->type = type;
    new->next = NULL;
    if (this->head == NULL) {
        this->head = new;
        this->size++;
        return;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    this->size++;
}

void removeNode(map_t *this, char *key)
{
    node_t *tmp = this->head;
    node_t *prev = NULL;

    if (tmp != NULL && strcmp(tmp->key, key) == 0) {
        this->head = tmp->next;
        free(tmp);
        this->size--;
        return;
    }
    while (tmp != NULL && strcmp(tmp->key, key) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    prev->next = tmp->next;
    free(tmp);
    this->size--;
}

void clear(map_t *this)
{
    node_t *tmp = this->head;
    node_t *next = NULL;

    while (tmp != NULL) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    this->head = NULL;
    this->size = 0;
}

void view(map_t *this)
{
    for (node_t *curr = this->head; curr != NULL; curr = curr->next)
        printf("key: %s : %s\n", curr->key, (char *)curr->data);
}
