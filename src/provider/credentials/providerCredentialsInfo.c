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

    int nameLength = strlen("Hardeol");
    credentials->name = malloc(sizeof(char) * (nameLength + 1));
    credentials->description = malloc(sizeof(char) * (strlen("Throughout Heaven and Earth, I alone am the Honored One") + 1));
    credentials->pp = malloc(sizeof(char) * (strlen("config/general/credentials/") + nameLength + strlen(".png") + 1));

    strcpy(credentials->name, "Hardeol");
    strcpy(credentials->description, "Throughout Heaven and Earth, I alone am the Honored One");
    strcpy(credentials->pp, "config/general/credentials/"); strcat(credentials->pp, credentials->name); strcat(credentials->pp, ".png");

    return credentials;
}

CredentialsInfo_t *credentialsInfoDragusheen(void)
{
    CredentialsInfo_t *credentials = malloc(sizeof(Credentials_t));

    int nameLength = strlen("Dragusheen");
    credentials->name = malloc(sizeof(char) * (nameLength + 1));
    credentials->description = malloc(sizeof(char) * (strlen("Hakuna Matata") + 1));
    credentials->pp = malloc(sizeof(char) * (strlen("config/general/credentials/") + nameLength + strlen(".png") + 1));

    strcpy(credentials->name, "Dragusheen");
    strcpy(credentials->description, "Hakuna Matata");
    strcpy(credentials->pp, "config/general/credentials/"); strcat(credentials->pp, credentials->name); strcat(credentials->pp, ".png");

    return credentials;
}

void destroyCredentialsInfo(CredentialsInfo_t *credentialsInfo)
{
    free(credentialsInfo->name);
    free(credentialsInfo->description);
    free(credentialsInfo);
}
