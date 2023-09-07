/*
** EPITECH PROJECT, 2023
** grade_de
** File description:
** serviceFiles.c
*/

#include "gradeDe.h"

char *getFileContent(char *filepath)
{
    struct stat file;
    stat(filepath, &file);
    int fd;
    int size = file.st_size + 1;
    char *str = malloc(sizeof(char) * size);
    for (int i = 0; i < size ; i++) str[i] = '\0';

    fd = open(filepath, O_RDONLY);
    read(fd, str, size);

    return str;
}

void writeFileContent(char *filepath, char *content)
{
    int fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    write(fd, content, strlen(content));
    close(fd);
}

void appendFileContent(char *filepath, char *content)
{
    int fd = open(filepath, O_WRONLY | O_CREAT | O_APPEND, 0666);
    write(fd, content, strlen(content));
    close(fd);
}
