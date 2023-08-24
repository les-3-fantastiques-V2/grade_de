/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** map.h
*/

#ifndef GRADE_DE_MAP_H
    #define GRADE_DE_MAP_H

    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>

enum type {
    INT,
    CHAR,
    STR,
    OTHER
};

typedef struct node_s {
    char *key;
    void *data;
    enum type type;
    struct node_s *next;
}node_t;

typedef struct map_s {
    void (*pushFront)(struct map_s *, char *, void *, enum type);
    void (*pushBack)(struct map_s *, char *, void *, enum type);
    void (*remove)(struct map_s *, char *);
    void (*clear)(struct map_s *);
    void (*view)(struct map_s *);
    void (*free)(struct map_s *);
    int (*length)(struct map_s *);
    void *(*popBack)(struct map_s *);
    void *(*popFront)(struct map_s *);
    void *(*get)(struct map_s *, char *);

    int size;
    struct node_s *head;
} map_t;

void pushFront(map_t *this, char *key, void *data, enum type type);
void pushBack(map_t *this, char *key, void *data, enum type type);
void removeNode(map_t *this, char *key);
void clear(map_t *this);
void view(map_t *this);
void freeMap(map_t *this);
void freeMallocMap(map_t *this);
int length(map_t *this);
void *popBack(map_t *this);
void *popFront(map_t *this);
void *get(map_t *this, char *key);
map_t createMap(void);
map_t *createMallocMap(void);

#endif //GRADE_DE_MAP_H
