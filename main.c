/*
** EPITECH PROJECT, 2018
** CountIsland	
** File description:
** main.c	
*/

#include "main.h"

int main(int ac, char **av)
{
	char *file_content;
	char **map;

	if (ac != 2) {
		printf("Usage: ./a.out <map>\n");
		return 0;
	}
	file_content = read_file(av[1]);
	if (file_content == NULL)
		return (84);
	map = str_to_map(file_content);
	if (map == NULL)
		return (84);
	count_island(map);
	for (int i = 0; map[i]; ++i)
		printf("%s\n", map[i]);
	return (0);
}


char *read_file(char *file)
{
	struct stat stats;
	char *file_content;
	int fd;

	if (stat(file, &stats) == -1)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = malloc(sizeof(char) * stats.st_size);
	if (file_content == NULL)
		return (NULL);
	if (read(fd, file_content, stats.st_size) == -1)
		return (NULL);
	return file_content;
}

char **str_to_map(char *str)
{
	char **map;
	char *copy = strdup(str);
	int nlines = 0;

	if (!copy)
		return NULL;
	for (; strsep(&copy, "\n"); ++nlines);
	map = malloc(sizeof(char *) * (nlines + 2));
	for (int i = 0; i <= nlines; ++i)
		map[i] = strsep(&str, "\n");
	return map;
}