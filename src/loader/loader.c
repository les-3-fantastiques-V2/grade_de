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
    char *path = malloc(sizeof(char) * (strlen(game) + strlen("src/games//assets") + 1));
    memset(path, 0, strlen(game) + strlen("src/games//assets"));
    strcpy(path, "src/games/");
    strcat(path, game);
    strcat(path, "/assets");
    return path;
}

static char *nameTexture(char *file)
{
    int i = 0;

    while (file[i] != '.' && file[i] != '\0')
        i++;
    if (i == 0) return NULL;
    char *name = malloc(sizeof(char) * (i + 1));
    memset(name, 0, i + 1);
    strncpy(name, file, i);
    return name;
}

static void fillMap(char *path, map_t *assets)
{
    DIR *dir = opendir(path);
    struct dirent *file = NULL;

    while ((file = readdir(dir)) != NULL) {
        if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) {
            char *pathFile = getFilePath(path, file->d_name);
            char *nameText = nameTexture(file->d_name);
            if (nameText == NULL) continue;
            assets->pushFront(assets, strdup(nameText), sfTexture_createFromFile(pathFile, NULL), STR);
            free(pathFile);
            free(nameText);
        }
    }
    closedir(dir);
}

map_t *loadAssets(char *game)
{
    map_t *game_assets = createMallocMap();
    char *path = getPathAssets(game);

    fillMap(path, game_assets);
    free(path);
    return game_assets;
}

void destroyAssets(map_t *assets)
{
    for (node_t *curr = assets->head; curr != NULL; curr = curr->next) {
        sfTexture_destroy(curr->data);
        free(curr->key);
    }
    assets->free(assets);
}
