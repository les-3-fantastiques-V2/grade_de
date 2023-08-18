/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** loader.c
*/

#include "main.h"
#include <dirent.h>

static char *getPathAssets(char *game)
{
    char *path = malloc(sizeof(char) * (strlen(game) + strlen("src/games//assets")));
    memset(path, 0, strlen(game) + strlen("src/games//assets"));
    strcpy(path, "src/games/");
    strcat(path, game);
    strcat(path, "/assets");
    return path;
}

static char *name_texture(char *file)
{
    int i = 0;

    while (file[i] != '.' && file[i] != '\0')
        i++;
    char *name = malloc(sizeof(char) * (i + 1));
    memset(name, 0, strlen(file) + 1);
    strncpy(name, file, i);
    return name;
}

static void fill_map(char *path, map_t *assets)
{
    DIR *dir = opendir(path);
    struct dirent *file = NULL;

    while ((file = readdir(dir)) != NULL) {
        if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
            assets->pushFront(assets, name_texture(file->d_name), sfTexture_createFromFile(file->d_name, NULL), STR);
    }
    closedir(dir);
}

map_t *load_assets(char *game)
{
    map_t *game_assets = createMallocMap();
    char *path = getPathAssets(game);

    fill_map(path, game_assets);
    free(path);
    return game_assets;
}

void destroy_assets(map_t *assets)
{
    for (node_t *curr = assets->head; curr != NULL; curr = curr->next) {
        sfTexture_destroy(curr->data);
        free(curr->key);
    }
    assets->free(assets);
}
