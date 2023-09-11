/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerCredentials.c
*/

#include "gradeDe.h"

CredentialsInfo_t *(*credentialsInfoList[CREDENTIALS_MAX])(void) = {
    &credentialsInfoDragusheen,
    &credentialsInfoHardeol,
};

void destroyCredentials(Credentials_t *credentials)
{
    sfText_destroy(credentials->name);
    sfText_destroy(credentials->description);
    sfCircleShape_destroy(credentials->ppCircle);
    sfTexture_destroy(credentials->ppTexture);
    free(credentials);
}

Credentials_t *createCredentialsById(CREDENTIALS_E credentialsId)
{
    CredentialsInfo_t *credentialsInfo = credentialsInfoList[credentialsId]();
    Credentials_t *credentials = malloc(sizeof(Credentials_t));

    if (credentials == NULL) return NULL;
    credentials->id = credentialsId;
    credentials->name = createText(credentialsInfo->name, (sfVector2f){500, 100}, 40, FONT_SPICY_PIZZA);
    credentials->description = createTextWithMaxWidth(credentialsInfo->description, (sfVector2f){500, 150}, 30, FONT_SPICY_PIZZA, 500);
    credentials->ppTexture = sfTexture_createFromFile(credentialsInfo->pp, NULL);
    credentials->ppCircle = createCircleShape(50, sfWhite, (sfVector2f){1050, 100});
    sfCircleShape_setTexture(credentials->ppCircle, credentials->ppTexture, sfTrue);
    sfCircleShape_setOutlineThickness(credentials->ppCircle, 5);
    sfCircleShape_setOutlineColor(credentials->ppCircle, (sfColor) {99, 50, 79, 255});

    destroyCredentialsInfo(credentialsInfo);
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
    renderCircleShape(credentials->ppCircle);
}
