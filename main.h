/*
** EPITECH PROJECT, 2018
** CountIsland	
** File description:
** main.h	
*/

#ifndef COUNTISLAND_MAIN_H
#define COUNTISLAND_MAIN_H

#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

char *read_file(char *file);
char **str_to_map(char *str);

void count_island(char **map);
void count_neighbors(char **map, char digit, int i, int j);

#endif //COUNTISLAND_MAIN_H
