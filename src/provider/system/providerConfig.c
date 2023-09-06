/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** providerConfig.c
*/

#include "gradeDe.h"

Config_t *getConfig(void)
{
    static Config_t config;
    return &config;
}

void addConfig(char *name, char *value)
{
    Config_t *config = getConfig();
    ConfigList_t *newConfig = malloc(sizeof(ConfigList_t));

    newConfig->name = malloc(sizeof(char) * (strlen(name) + 1));
    newConfig->value = malloc(sizeof(char) * (strlen(value) + 1));

    strcpy(newConfig->name, name);
    strcpy(newConfig->value, value);

    newConfig->next = config->configList;
    config->configList = newConfig;
}

void initConfig(void)
{
    Config_t *config = getConfig();

    config->configList = NULL;
    char *configContent = getFileContent("config/settings.csv");
    char **configTable = stringToWordArray(configContent, "\n");

    for (int i = 0; configTable[i] != NULL; i++) {
        char **configLine = stringToWordArray(configTable[i], ";");
        addConfig(configLine[0], configLine[1]);
        freeCharArray(configLine);
    }
    freeCharArray(configTable);
}

void destroyConfig(void)
{
    Config_t *config = getConfig();

    ConfigList_t *currentConfig = config->configList;
    ConfigList_t *nextConfig = NULL;
    while (currentConfig != NULL) {
        nextConfig = currentConfig->next;
        free(currentConfig->name);
        free(currentConfig->value);
        free(currentConfig);
        currentConfig = nextConfig;
    }
}

char *getConfigValueByName(char *name)
{
    Config_t *config = getConfig();

    ConfigList_t *currentConfig = config->configList;
    while (currentConfig != NULL) {
        if (strcmp(currentConfig->name, name) == 0)
            return currentConfig->value;
        currentConfig = currentConfig->next;
    }
    return NULL;
}


void _saveConfig(ConfigList_t *currentConfig)
{
    if (currentConfig == NULL) {
        writeFileContent("config/settings.csv", "");
        return;
    } else {
        _saveConfig(currentConfig->next);
        char *configLine = malloc(sizeof(char) * (strlen(currentConfig->name) + strlen(currentConfig->value) + 2));
        strcpy(configLine, currentConfig->name);
        strcat(configLine, ";");
        strcat(configLine, currentConfig->value);
        strcat(configLine, ";\n");
        appendFileContent("config/settings.csv", configLine);
        free(configLine);
    }
}

void saveConfig(void)
{
    Config_t *config = getConfig();
    ConfigList_t *currentConfig = config->configList;
    _saveConfig(currentConfig);
}

void setConfig(char *name, char *value)
{
    Config_t *config = getConfig();
    ConfigList_t *currentConfig = config->configList;

    while (currentConfig != NULL) {
        if (strcmp(currentConfig->name, name) == 0) {
            free(currentConfig->value);
            currentConfig->value = malloc(sizeof(char) * (strlen(value) + 1));
            strcpy(currentConfig->value, value);
            return;
        }
        currentConfig = currentConfig->next;
    }
    addConfig(name, value);
}
