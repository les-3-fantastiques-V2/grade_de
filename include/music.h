/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** music.h
*/

#ifndef MUSIC_H_
    #define MUSIC_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== ENUM ====================*/


    typedef enum MUSIC {
        MUSIC_HOME_AMBIENT,
        MUSIC_MAX,
    } MUSIC_E;


/*==================== STRUCTURE =====================*/


    typedef struct structMusic {
        MUSIC_E musicId;
        sfMusic *music;
    } Music_t;

    typedef struct structMusicList {
        Music_t *music;
        struct structMusicList *next;
    } MusicList_t;

    typedef struct structMusicPlayer {
        MusicList_t *musicList;
        Music_t *currentMusic;
        float volume;
    } MusicPlayer_t;


/*==================== FUNCTION ====================*/


        // Music
    void destroyMusic(Music_t *music);
    Music_t *getMusicById(MUSIC_E musicId);
    Music_t *createMusicById(MUSIC_E musicId);

        // Music List
    void initMusicListStruct(void);
    void destroyMusicListStruct(void);

        // Music Player
    void initMusicPlayerStruct(void);
    void changeMusic(MUSIC_E musicId);
    void destroyMusicPlayerStruct(void);
    void changeMusicVolume(float volume);


/*==================== MACRO ====================*/


#endif /*MUSIC_H_*/