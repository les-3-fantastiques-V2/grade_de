/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** gradeDe.h
*/

#ifndef GRADE_DE_H_
    #define GRADE_DE_H_

/*=========================== INCLUDE ========================*/


//General Include
    #include <fcntl.h>
    #include <math.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>


//Personal Include

    #include "controller/manager/manager.h"


    #include "provider/button.h"
    #include "provider/cursor.h"
    #include "provider/font.h"
    #include "provider/music.h"
    #include "provider/scene.h"
    #include "provider/sound.h"
    #include "provider/system.h"


    #include "service/service.h"


    #include "credentials.h"
    #include "settingsSections.h"
    #include "statsSections.h"
    #include "gameSlot.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


/*==================== FUNCTION ====================*/


/*==================== MACRO ====================*/


    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720


#endif /*GRADE_DE_H_*/

