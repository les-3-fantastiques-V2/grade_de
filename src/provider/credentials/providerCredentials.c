/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerCredentials.c
*/

#include "gradeDe.h"

char *credentialsNameList[CREDENTIALS_MAX] = {
    "Dragusheen",
    "Hardeol",
};

char *credentialsDescriptionList[CREDENTIALS_MAX] = {
    "Hakuna Matata",
    "Throughout Heaven and Earth, I alone am the Honored One",
};


void destroyCredentials(Credentials_t *credentials)
{
    sfText_destroy(credentials->name);
    sfText_destroy(credentials->description);
    free(credentials);
}

Credentials_t *createCredentialsById(CREDENTIALS_E credentialsId)
{
    Credentials_t *credentials = malloc(sizeof(Credentials_t));

    if (credentials == NULL) return NULL;
    credentials->id = credentialsId;
    credentials->name = createText(credentialsNameList[credentialsId], (sfVector2f){450, 100}, 40, FONT_SPICY_PIZZA);
    credentials->description = createText(credentialsDescriptionList[credentialsId], (sfVector2f){450, 150}, 30, FONT_SPICY_PIZZA);
    return credentials;
}

Credentials_t *getCredentialsById(CREDENTIALS_E credentialsId)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
    CredentialsList_t *credentialsList = sceneMenuStats->credentialsSection->credentialsList;

    if (credentialsId < 0 || credentialsId > CREDENTIALS_MAX) return NULL;
    while (credentialsList != NULL) {
        if (credentialsList->credentials->id == credentialsId)
            return credentialsList->credentials;
        credentialsList = credentialsList->next;
    }

    return NULL;
}

void renderCredentials(Credentials_t *credentials)
{
    renderText(credentials->name);
    renderText(credentials->description);
}
