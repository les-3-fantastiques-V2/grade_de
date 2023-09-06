/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSoundPlayer.c
*/

#include "gradeDe.h"

void initSoundPlayerStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    gradeDe->soundPlayer = malloc(sizeof(SoundPlayer_t));
    initSoundListStruct();

    char *soundVolume = getConfigValueByName("soundVolume");
    if (soundVolume != NULL) {
        int volume = (int)atof(soundVolume);
        gradeDe->soundPlayer->volume = volume;
    } else {
        setConfig("soundVolume", "100");
        gradeDe->soundPlayer->volume = 100;
    }
    gradeDe->soundPlayer->currentSound = NULL;
}

void destroySoundPlayerStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    destroySoundListStruct();
    free(gradeDe->soundPlayer);
}

void changeSoundVolume(float volume)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    gradeDe->soundPlayer->volume = volume;
    sfSound_setVolume(gradeDe->soundPlayer->currentSound->sound, volume);
    char *volumeStr = intToString((int)volume);
    setConfig("soundVolume", volumeStr);
    free(volumeStr);
}

void playSound(SOUND_E soundId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    if (gradeDe->soundPlayer->currentSound != NULL)
        sfSound_stop(gradeDe->soundPlayer->currentSound->sound);

    gradeDe->soundPlayer->currentSound = getSoundById(soundId);
    if (gradeDe->soundPlayer->currentSound == NULL) return;
    sfSound_setVolume(gradeDe->soundPlayer->currentSound->sound, gradeDe->soundPlayer->volume);
    sfSound_play(gradeDe->soundPlayer->currentSound->sound);
}

float getSoundVolume(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    return gradeDe->soundPlayer->volume;
}
