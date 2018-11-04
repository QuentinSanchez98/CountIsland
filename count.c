/*
** EPITECH PROJECT, 2018
** CountIsland	
** File description:
** count.c	
*/

#include "main.h"

void count_island(char **map)
{
	char digit = '0';

	for (int i = 0; map[i]; ++i) {
		for (int j = 0; map[i][j]; ++j) {
			if (map[i][j] == '*') {
				count_neighbors(map, digit, i, j);
				digit = digit + 1;
			}
		}
	}
}

void count_neighbors(char **map, char digit, int i, int j)
{
	if (map[i][j] == '*') {
		map[i][j] = digit;
		if (map[i + 1])
			count_neighbors(map, digit, i + 1, j);
		if (i > 0)
			count_neighbors(map, digit, i - 1, j);
		if (map[i][j])
			count_neighbors(map, digit, i, j + 1);
		if (j > 0)
			count_neighbors(map, digit, i, j - 1);
	}
}