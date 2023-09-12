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

    // Controller
        #include "controller/manager/manager.h"

        #include "controller/scene/gamePacman/gamePacman.h"

        #include "controller/scene/menuChooseGame/gameSlot.h"
        #include "controller/scene/menuChooseGame/menuChooseGame.h"

        #include "controller/scene/menuSetting/menuSetting.h"
        #include "controller/scene/menuSetting/settingsSections.h"

        #include "controller/scene/menuStats/credentials.h"
        #include "controller/scene/menuStats/menuStats.h"
        #include "controller/scene/menuStats/statsSections.h"


    // Provider
        #include "provider/button.h"
        #include "provider/cursor.h"
        #include "provider/font.h"
        #include "provider/music.h"
        #include "provider/scene.h"
        #include "provider/sound.h"
        #include "provider/system.h"


    // Service
        #include "service/service.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


/*==================== FUNCTION ====================*/


/*==================== MACRO ====================*/


    #define WINDOW_WIDTH 1280
    #define WINDOW_HEIGHT 720


#endif /*GRADE_DE_H_*/

