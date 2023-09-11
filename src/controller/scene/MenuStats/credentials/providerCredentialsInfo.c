/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerCredentialsInfo.c
*/

#include "gradeDe.h"

CredentialsInfo_t *credentialsInfoHardeol(void)
{
    CredentialsInfo_t *credentials = malloc(sizeof(Credentials_t));

    char *name = "Hardeol";
    char *description = "Throughout Heaven and Earth, I alone am the Honored One.";

    int nameLength = strlen(name);
    credentials->name = malloc(sizeof(char) * (nameLength + 1));
    strcpy(credentials->name, name);
    int descriptionLength = strlen(description);
    credentials->description = malloc(sizeof(char) * (descriptionLength + 1));
    strcpy(credentials->description, description);
    credentials->pp = malloc(sizeof(char) * (strlen("config/general/credentials/") + nameLength + strlen(".png") + 1));
    strcpy(credentials->pp, "config/"); strcat(credentials->pp, credentials->name); strcat(credentials->pp, ".png");

    return credentials;
}

CredentialsInfo_t *credentialsInfoDragusheen(void)
{
    CredentialsInfo_t *credentials = malloc(sizeof(Credentials_t));

    char *name = "Dragusheen";
    char *description = "I'm not stupid, i'm just too Lazy to show how Smart i am...";

    int nameLength = strlen(name);
    credentials->name = malloc(sizeof(char) * (nameLength + 1));
    strcpy(credentials->name, name);
    int descriptionLength = strlen(description);
    credentials->description = malloc(sizeof(char) * (descriptionLength + 1));
    strcpy(credentials->description, description);
    credentials->pp = malloc(sizeof(char) * (strlen("config/general/credentials/") + nameLength + strlen(".png") + 1));
    strcpy(credentials->pp, "config/"); strcat(credentials->pp, credentials->name); strcat(credentials->pp, ".png");

    return credentials;
}

void destroyCredentialsInfo(CredentialsInfo_t *credentialsInfo)
{
    free(credentialsInfo->name);
    free(credentialsInfo->description);
    free(credentialsInfo);
}
