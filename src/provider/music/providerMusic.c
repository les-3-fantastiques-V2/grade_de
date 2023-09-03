/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerMusic.c
*/

#include "gradeDe.h"

char *musicName[MUSIC_MAX] = {
    "HomeAmbientMusic",
};

void destroyMusic(Music_t *music)
{
    sfMusic_destroy(music->music);
    free(music);
}

Music_t *createMusicById(MUSIC_E musicId)
{
    Music_t *music = malloc(sizeof(Music_t));
    char *musicPath = malloc(sizeof(char) * (strlen("assets/music/") + strlen(musicName[musicId]) + strlen(".ogg") + 1));

    if (music == NULL || musicPath == NULL) return NULL;
    strcpy(musicPath, "assets/music/");
    strcat(musicPath, musicName[musicId]);
    strcat(musicPath, ".ogg");

    music->musicId = musicId;
    music->music = sfMusic_createFromFile(musicPath);
    sfMusic_setLoop(music->music, sfTrue);

    free(musicPath);
    if (music->music == NULL) return NULL;
    return music;
}

Music_t *getMusicById(MUSIC_E musicId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    MusicList_t *musicList = gradeDe->musicPlayer->musicList;

    if (musicId < 0 || musicId > MUSIC_MAX) return NULL;
    while (musicList != NULL) {
        if (musicList->music->musicId == musicId)
            return musicList->music;
        musicList = musicList->next;
    }
    return NULL;
}
