/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** manager.h
*/

#ifndef MANAGER_H_
    #define MANAGER_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include
    #include "provider/cursor.h"
    #include "provider/music.h"
    #include "provider/scene.h"
    #include "provider/sound.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


/*==================== FUNCTION ====================*/


    // Event
        void eventManager(SceneConfig_t *sceneConfig);

    // Game Slot
        void renderGameSlotList(void);
        int getGameSlotPositionIdByMousePosition(void);

    // Mouse Cursor
        void renderMouseCursor(void);
        CURSOR_E getMouseCursorId(void);
        void initMouseCursorStruct(void);
        void destroyMouseCursorStruct(void);
        CURSOR_TYPE_E getMouseCursorType(void);
        void changeMouseCursor(CURSOR_E cursorId, CURSOR_TYPE_E type);

    // Music Player
        float getMusicVolume(void);
        void initMusicPlayerStruct(void);
        void changeMusic(MUSIC_E musicId);
        void destroyMusicPlayerStruct(void);
        void changeMusicVolume(float volume);

    // Scene
        void sceneManager(void);
        void changeScene(SCENE_E sceneId);

    // Sound Player
        float getSoundVolume(void);
        void playSound(SOUND_E soundId);
        void initSoundPlayerStruct(void);
        void destroySoundPlayerStruct(void);
        void changeSoundVolume(float volume);

    // Transition
        void renderTransition(void);
        void playTransition(SCENE_E nextScene);


/*==================== MACRO ====================*/


#endif /*MANAGER_H_*/

