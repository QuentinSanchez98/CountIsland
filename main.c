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

	if (ac != 2) {
		printf("Usage: ./a.out <map>\n");
		return 0;
	}
	file_content = read_file(av[1]);
	if (file_content == NULL)
		return (84);
	count_island(file_content);
	printf("%s", file_content);
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
	if (read(fd, file_content, stats.st_size) == -1)
		return (NULL);
	return file_content;
}
