#include "so_long.h"

void	is_map_valid(t_game *game)
{
	if (check_filename(game->filename) == 0)
		exit_error(game, "Error: invalid file name or extension\n");
	if (check_map_rectangular(game->map)== 0)
		exit_error(game, "Error: map is not rectangular");
	if (check_map_walls(game->map, game->lines, game->width) == 0)
		exit_error(game, "Error: map must be surrounded by walls\n");
	if (check_invalid_char(game->map, game->lines) == 0)
		exit_error(game, "Error: map contains invalid characters\n");
	check_map_elements(game, game->map, game->lines);
	if (check_valid_path(game) == 0)
		exit_error(game, "Error: No valid path\n");
}

int	check_map_rectangular(char **map)
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

void check_map_elements(t_game *game, char **map, int lines)
{
	if (check_player(map, lines) == 0)
		exit_error(game, "Error: map must contain exactly one player (P)");
	if (check_exit(map, lines) == 0)
		exit_error(game, "Error: map must contain exactly one exit (E)");
	if (check_collectibles(map, lines) == 0)
		exit_error(game, "Error: map must contain at least one collectible (C)");
	if (check_enemy(map, lines) == 0)
		exit_error(game, "Error: map must contain at least one enemy (E)");
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
			if (map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != '0' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}