#include "so_long.h"

int	check_valid_path(t_game *game)
{
	char **temp_map;

	temp_map = copy_map(game->map, game->lines, game->width);
	if (!temp_map)
		exit_error(game, "Error: failed to copy map\n");
	find_player(game, temp_map);
	floodfill(temp_map, game->x_player, game->y_player);
	if (is_path_reachable(temp_map, game->lines, game->width) == 0)
	{
		free(temp_map);
		return (0);

	}
	else
	{
		free(temp_map);	
		return (1);
	}
}

char **copy_map(char **src, int lines, int width)
{
	char **dst;
	int i;

	i = 0;
	dst = malloc(sizeof(char *) * (lines + 1));
	if (!dst)
		return NULL;
	while (i < lines)
	{
		dst[i] = malloc(sizeof(char) * (width + 1));
		ft_strcpy(dst[i], src[i]);
		i++;
	}
	return (dst);
}

void	find_player(t_game *game, char **map)
{
	int i;
	int j;

    game->x_player = -1;
    game->y_player = -1;
	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] == 'P')
			{
				game->x_player = j;
				game->y_player = i;
				return;
			}
			j++;
		}
		i++;
	}
	exit_error(game, "Error: player not found in map\n");
}

void	floodfill(char **map, int x, int y)
{
	if (y < 0 || x < 0 || map[y] == NULL || map[y][x] == '\0')
		return;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return;
	if (map[y][x] == 'P' || map[y][x] == '0' || map[y][x] == 'E' || map[y][x] == 'C')
		map[y][x] = 'V';

	floodfill(map, x + 1, y);
	floodfill(map, x - 1, y);
	floodfill(map, x, y + 1);
	floodfill(map, x, y - 1);
}

int	is_path_reachable(char **map, int lines, int width)
{
	int i;
	int j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}