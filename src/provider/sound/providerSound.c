/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerSound.c
*/

#include "gradeDe.h"

char *soundName[SOUND_MAX] = {
    "ButtonPressed",
    "LunchApplication",
    "Swipe"
};

void destroySound(Sound_t *sound)
{
    sfSound_destroy(sound->sound);
    sfSoundBuffer_destroy(sound->soundBuffer);
    free(sound);
}

Sound_t *createSoundById(SOUND_E soundId)
{
    Sound_t *sound = malloc(sizeof(Sound_t));
    char *soundPath = malloc(sizeof(char) * (strlen("assets/sound/") + strlen(soundName[soundId]) + strlen(".ogg") + 1));

    if (sound == NULL || soundPath == NULL) return NULL;
    strcpy(soundPath, "assets/sound/");
    strcat(soundPath, soundName[soundId]);
    strcat(soundPath, ".ogg");

    sound->soundId = soundId;
    sound->soundBuffer = sfSoundBuffer_createFromFile(soundPath);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->soundBuffer);

    free(soundPath);
    if (sound->sound == NULL) return NULL;
    return sound;
}

Sound_t *getSoundById(SOUND_E soundId)
{
    GradeDe_t *gradeDe = getGradeDeStruct();
    SoundList_t *soundList = gradeDe->soundPlayer->soundList;

    if (soundId < 0 || soundId > SOUND_MAX) return NULL;
    while (soundList != NULL) {
        if (soundList->sound->soundId == soundId)
            return soundList->sound;
        soundList = soundList->next;
    }
    return NULL;
}
