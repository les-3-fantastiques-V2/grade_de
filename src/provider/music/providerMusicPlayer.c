/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerMusicPlayer.c
*/

#include "gradeDe.h"

void initMusicPlayerStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    gradeDe->musicPlayer = malloc(sizeof(MusicPlayer_t));
    initMusicListStruct();

    gradeDe->musicPlayer->volume = 15;
    gradeDe->musicPlayer->currentMusic = NULL;
}

void destroyMusicPlayerStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    destroyMusicListStruct();
    free(gradeDe->musicPlayer);
}

void changeMusicVolume(float volume)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    gradeDe->musicPlayer->volume = volume;
    sfMusic_setVolume(gradeDe->musicPlayer->currentMusic->music, volume);
}

void changeMusic(MUSIC_E musicId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    if (gradeDe->musicPlayer->currentMusic != NULL) {
        if (gradeDe->musicPlayer->currentMusic->musicId == musicId) return;

        sfMusic_stop(gradeDe->musicPlayer->currentMusic->music);
    }

    gradeDe->musicPlayer->currentMusic = getMusicById(musicId);
    if (gradeDe->musicPlayer->currentMusic == NULL) return;
    sfMusic_setVolume(gradeDe->musicPlayer->currentMusic->music, gradeDe->musicPlayer->volume);
    sfMusic_play(gradeDe->musicPlayer->currentMusic->music);
}

float getMusicVolume(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    return gradeDe->musicPlayer->volume;
}
