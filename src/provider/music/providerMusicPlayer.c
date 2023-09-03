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

    gradeDe->musicPlayer->currentMusic = getMusicById(MUSIC_HOME_AMBIENT);
    gradeDe->musicPlayer->volume = 100;
    sfMusic_setVolume(gradeDe->musicPlayer->currentMusic->music, gradeDe->musicPlayer->volume);
    sfMusic_play(gradeDe->musicPlayer->currentMusic->music);
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
    if (gradeDe->musicPlayer->currentMusic->musicId == musicId) return;

    sfMusic_stop(gradeDe->musicPlayer->currentMusic->music);
    gradeDe->musicPlayer->currentMusic = getMusicById(musicId);
    sfMusic_setVolume(gradeDe->musicPlayer->currentMusic->music, gradeDe->musicPlayer->volume);
    sfMusic_play(gradeDe->musicPlayer->currentMusic->music);
}
