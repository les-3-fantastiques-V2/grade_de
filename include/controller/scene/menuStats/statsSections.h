/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** statsSections.h
*/

#ifndef STATS_SECTIONS_H_
    #define STATS_SECTIONS_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include
    #include "credentials.h"
    #include "provider/button.h"


/*==================== ENUM ====================*/

    typedef enum STATS_SECTION {
        STATS_SECTION_APPLICATIONS,
        STATS_SECTION_CREDENTIALS,
    } STATS_SECTION_E;


/*==================== STRUCTURE =====================*/

    typedef struct structSectionCredentials {
        bool asNext;
        bool asPrevious;
        CREDENTIALS_E credentialsId;
        sfText *title;
        Credentials_t *currentCredentials;
        CredentialsList_t *credentialsList;
        Button_t *leftArrowButton;
        Button_t *rightArrowButton;
    } StatsCredentialsSection_t;

    typedef struct structSectionApplications {
        sfText *title;
        sfText *applicationLabel;
        sfText *applicationCount;
    } StatsApplicationsSection_t;


/*==================== FUNCTION ====================*/


    // Stats Section
        void initStatsSection(void);
        void renderStatsSection(void);
        void destroyStatsSection(void);
        void changeStatsSection(STATS_SECTION_E section);

    // Applications Section
        void initStatsApplicationsSection(void);
        void renderStatsApplicationsSection(void);
        void destroyStatsApplicationsSection(void);

    // Credentials Section
        void initStatsCredentialsSection(void);
        void renderStatsCredentialsSection(void);
        void destroyStatsCredentialsSection(void);


/*==================== MACRO ====================*/


#endif /*STATS_SECTIONS_H_*/

