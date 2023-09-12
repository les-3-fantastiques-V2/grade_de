/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** menuSTATS.h
*/

#ifndef MENU_STATS_H_
    #define MENU_STATS_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "statsSections.h"
    #include "provider/button.h"


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    typedef struct structSceneMenuStats {
        STATS_SECTION_E currentSection;
        sfRectangleShape *background;
        sfConvexShape *backgroundMenu;
        Button_t *backButton;
        sfConvexShape *line;
        StatsApplicationsSection_t *applicationsSection;
        StatsCredentialsSection_t *credentialsSection;
    } SceneMenuStats_t;


/*==================== FUNCTION ====================*/


    // Scene Menu Stats
        void loadSceneMenuStats(void);
        void renderSceneMenuStats(void);
        void destroySceneMenuStats(void);
        void eventManagerSceneMenuStats(void);
        SceneMenuStats_t *getSceneMenuStatsStruct(void);


/*==================== MACRO ====================*/


#endif /*MENU_STATS_H_*/