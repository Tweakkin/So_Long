#include "so_long.h"

int	is_map_valid(char **map, int lines, int width)
{
	if (check_map_rectangulaire(map)== 0)
		return (0);
	else if (check_map_walls(map, lines, width) == 0)
		return(0);
	else if (check_map_elements(map, lines) == 0)
		return (0);
	else if (check_invalid_char(map, lines) == 0)
		return (0);
	else
		return (1);
}

int	check_map_rectangulaire(char **map)
{
	int i;
	int j;
	int temp;

	i = 0;
	temp = -1;
	while (map[i] != NULL)
	{
		j = ft_strlen(map[i]);
		if (j > 0 && map[i][j - 1] == '\n')
		{
			if (map[i][j - 2] == '\r')
			{
				j--;
			}
			j--;
		}
		if (temp != j && temp != -1)
			return 0;
		else
			temp = j;
		i++;
	}
	return 1;
}

int	check_map_walls(char **map, int lines, int width)
{
	int j;

	j = 0;
	while (map[0][j] != '\0' && map[0][j] != '\r' && map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map[lines - 1][j] != '\0' && map[lines - 1][j] != '\r' && map[lines - 1][j] != '\n')
	{
		if (map[lines - 1][j] != '1')
			return (0);
		j++;
	}
	if (check_middle_lines(map, lines, width) == 0)
		return (0);
	else
		return (1);
}

int check_map_elements(char **map, int lines)
{
	if (check_player(map, lines) == 0)
		return (0);
	else if (check_exit(map, lines) == 0)
		return (0);
	else if (check_collectibles(map, lines) == 0)
		return (0);
	else
		return (1);
}

int check_invalid_char(char **map, int lines)
{
	int i;
	int j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0' && map[i][j] != '\r')
		{
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}