/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSoundList.c
*/

#include "gradeDe.h"

static void _addSound(SOUND_E soundId, SoundList_t **soundList)
{
    Sound_t *sound = createSoundById(soundId);

    if (sound == NULL) return;

    SoundList_t *newSoundList = malloc(sizeof(SoundList_t));
    newSoundList->sound = sound;
    newSoundList->next = *soundList;
    *soundList = newSoundList;
}

void initSoundListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    SoundList_t *soundList = NULL;

    for (int i = 0; i < SOUND_MAX; i++) {
        _addSound(i, &soundList);
    }

    gradeDe->soundPlayer->soundList = soundList;
}

void destroySoundListStruct(void)
{
    GradeDe_t *gradeDe = getGradeDeStruct();

    while(gradeDe->soundPlayer->soundList != NULL) {
        SoundList_t *soundStruct = gradeDe->soundPlayer->soundList;
        gradeDe->soundPlayer->soundList = gradeDe->soundPlayer->soundList->next;
        destroySound(soundStruct->sound); free(soundStruct);
    }
}
