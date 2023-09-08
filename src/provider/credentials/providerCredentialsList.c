/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerCredentialsList.c
*/

#include "gradeDe.h"

static void _addCredentials(CREDENTIALS_E credentialsId, CredentialsList_t **credentialsList)
{
    Credentials_t *credentials = createCredentialsById(credentialsId);

    if (credentials == NULL) return;

    CredentialsList_t *newCredentialsList = malloc(sizeof(CredentialsList_t));
    newCredentialsList->credentials = credentials;
    newCredentialsList->next = *credentialsList;
    *credentialsList = newCredentialsList;
}

// TODO: Fix segfault

void initCredentialsListStruct(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();
    CredentialsList_t *credentialsList = NULL;

    for (int i = 0; i < CREDENTIALS_MAX; i++) _addCredentials(i, &credentialsList);

    sceneMenuStats->credentialsSection->credentialsList = credentialsList;
}

void destroyCredentialsListStruct(void)
{
    SceneMenuStats_t *sceneMenuStats = getSceneMenuStatsStruct();

    while (sceneMenuStats->credentialsSection->credentialsList != NULL) {
        CredentialsList_t *credentialsStruct = sceneMenuStats->credentialsSection->credentialsList;
        sceneMenuStats->credentialsSection->credentialsList = sceneMenuStats->credentialsSection->credentialsList->next;
        destroyCredentials(credentialsStruct->credentials); free(credentialsStruct);
    }
}
