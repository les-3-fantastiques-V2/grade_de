/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** credentials.h
*/

#ifndef CREDENTIALS_H_
    #define CREDENTIALS_H_

/*=========================== INCLUDE ========================*/


//General Include


//Personal Include


/*==================== ENUM ====================*/


typedef enum CREDENTIALS {
        CREDENTIALS_DRAGUSHEEN,
        CREDENTIALS_HARDEOL,
        CREDENTIALS_MAX,
    } CREDENTIALS_E;


/*==================== STRUCTURE =====================*/


    typedef struct structCredentials {
        CREDENTIALS_E id;
        sfText *name;
        sfText *description;
    } Credentials_t;

    typedef struct structCredentialsList {
        Credentials_t *credentials;
        struct structCredentialsList *next;
    } CredentialsList_t;


/*==================== FUNCTION ====================*/


        // Credentials
            void renderCredentials(Credentials_t *credentials);
            void destroyCredentials(Credentials_t *credentials);
            Credentials_t *getCredentialsById(CREDENTIALS_E credentialsId);
            Credentials_t *createCredentialsById(CREDENTIALS_E credentialsId);

        // Credentials List
            void initCredentialsListStruct(void);
            void destroyCredentialsListStruct(void);


/*==================== MACRO ====================*/


#endif /*CREDENTIALS_H_*/