#include "so_long.h"

int	check_middle_lines(char **map, int lines, int width)
{
	int i;

	i = 1;
	while (i < (lines - 1))
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int check_collectibles(char **map, int lines)
{
	int i;
	int collectibles;
	int j;

	i = 0;
	collectibles = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0' && map[i][j] != '\r')
		{
			if (map[i][j] == 'C')
				collectibles++;
			j++;
		}
		i++;
	}
	if (collectibles < 1)
		return (0);
	else
		return (1);
}

int check_exit(char **map, int lines)
{
	int i;
	int exit;
	int j;

	i = 0;
	exit = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0' && map[i][j] != '\r')
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1)
		return (0);
	else
		return (1);
}

int check_player(char **map, int lines)
{
	int i;
	int player;
	int j;

	i = 0;
	player = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0' && map[i][j] != '\r')
		{
			if (map[i][j] == 'P')
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		return (0);
	else
		return (1);
}