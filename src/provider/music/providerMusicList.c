/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerMusicList.c
*/

#include "gradeDe.h"

static void _addMusic(MUSIC_E musicId, MusicList_t **musicList)
{
    Music_t *music = createMusicById(musicId);

    if (music == NULL) return;

    MusicList_t *newMusicList = malloc(sizeof(MusicList_t));
    newMusicList->music = music;
    newMusicList->next = *musicList;
    *musicList = newMusicList;
}

void initMusicListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    MusicList_t *musicList = NULL;

    for (int i = 0; i < MUSIC_MAX; i++) {
        _addMusic(i, &musicList);
    }

    gradeDe->musicPlayer->musicList = musicList;
}

void destroyMusicListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    while (gradeDe->musicPlayer->musicList != NULL) {
        MusicList_t *musicStruct = gradeDe->musicPlayer->musicList;
        gradeDe->musicPlayer->musicList = gradeDe->musicPlayer->musicList->next;
        destroyMusic(musicStruct->music); free(musicStruct);
    }
}