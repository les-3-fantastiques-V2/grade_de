/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** config.h
*/

#ifndef CONFIG_H_
    #define CONFIG_H_

/*=========================== INCLUDE ========================*/


//General Include

//Personal Include


/*==================== ENUM ====================*/


/*==================== STRUCTURE =====================*/


    typedef struct linkedListConfiguration {
        char *name;
        char *value;
        struct linkedListConfiguration *next;
    } ConfigList_t;

    typedef struct structConfiguration {
        ConfigList_t *configList;
    } Config_t;


/*==================== FUNCTION ====================*/


    void initConfig(void);
    void saveConfig(void);
    void destroyConfig(void);
    void addConfig(char *name, char *value);
    void setConfig(char *name, char *value);

    char *getConfigValueByName(char *name);

    Config_t *getConfig(void);


/*==================== MACRO ====================*/


#endif /*CONFIG_H_*/
