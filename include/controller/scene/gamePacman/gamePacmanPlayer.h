/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gamePacmanPlayer.h
*/

#ifndef GAME_PACMAN_PLAYER_H_
    #define GAME_PACMAN_PLAYER_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include

/*==================== ENUM ====================*/


    typedef enum PACMAN_PLAYER_DIRECTION {
        PLAYER_PACMAN_DIRECTION_UP,
        PLAYER_PACMAN_DIRECTION_RIGHT,
        PLAYER_PACMAN_DIRECTION_DOWN,
        PLAYER_PACMAN_DIRECTION_LEFT,
        PLAYER_PACMAN_DIRECTION_NONE
    } PACMAN_PLAYER_DIRECTION_E;


/*==================== STRUCTURE =====================*/

    typedef struct structGamePacmanPlayer {
        sfRectangleShape *player;
        sfVector2f position;
        sfVector2i coord;
        sfClock *movingClock;
        PACMAN_PLAYER_DIRECTION_E direction;
        PACMAN_PLAYER_DIRECTION_E nextDirection;
    } GamePacmanPlayer_t;


/*==================== FUNCTION ====================*/


    // Pacman Game Player
        void initPacmanGamePlayer(void);
        void eventPacmanGamePlayer(void);
        void renderPacmanGamePlayer(void);
        void destroyPacmanGamePlayer(void);


/*==================== MACRO ====================*/


#endif /*GAME_PACMAN_PLAYER_H_*/