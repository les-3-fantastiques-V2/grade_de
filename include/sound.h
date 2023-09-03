/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** sound.h
*/

#ifndef SOUND_H_
    #define SOUND_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== ENUM ====================*/


    typedef enum SOUND {
        SOUND_BUTTON_PRESSED,
        SOUND_LUNCH_APPLICATION,
        SOUND_SWIPE,
        SOUND_MAX,
    } SOUND_E;


/*==================== STRUCTURE =====================*/


    typedef struct structSound {
        SOUND_E soundId;
        sfSoundBuffer *soundBuffer;
        sfSound *sound;
    } Sound_t;

    typedef struct structSoundList {
        Sound_t *sound;
        struct structSoundList *next;
    } SoundList_t;

    typedef struct structSoundPlayer {
        SoundList_t *soundList;
        Sound_t *currentSound;
        float volume;
    } SoundPlayer_t;


/*==================== FUNCTION ====================*/


        // Sound
    void destroySound(Sound_t *sound);
    Sound_t *getSoundById(SOUND_E soundId);
    Sound_t *createSoundById(SOUND_E soundId);

        // Sound List
    void initSoundListStruct(void);
    void destroySoundListStruct(void);

        // Sound Player
    void playSound(SOUND_E soundId);
    void initSoundPlayerStruct(void);
    void destroySoundPlayerStruct(void);
    void changeSoundVolume(float volume);


/*==================== MACRO ====================*/


#endif /*SOUND_H_*/