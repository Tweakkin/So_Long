#include "so_long.h"

void	display_map(t_game *game, int keycode)
{
    int x;
	int y;
    void *img;

    y = 0;
    while (y < game->lines)
    {
        x = 0;
        while (x < game->width)
        {
            if (game->map[y][x] == '0')
                img = game->img_wall;
            else if (game->map[y][x] == '1')
                img = game->img_limits;
            else if (game->map[y][x] == 'C')
                img = game->img_collectibles;
            else if (game->map[y][x] == 'E' && game->collectibles_num > game->collected)
                img = game->img_closed_exit;
            else if (game->map[y][x] == 'E' && game->collectibles_num == game->collected)
                img = game->img_opened_exit;
			else if (game->map[y][x] == 'P' && keycode == 100)
                img = game->img_player_right;
			else if (game->map[y][x] == 'P' && keycode == 97)
                img = game->img_player_left;
            else if (game->map[y][x] == 'P')
                img = game->img_player;
			else if (game->map[y][x] == 'X')
				img = game->img_enemy;
            else
                img = game->img_limits;
            mlx_put_image_to_window(game->mlx, game->mlx_window, img, x * 62, y * 62);
            x++;
        }
        y++;
    }
}

void	free_allocated(t_game *game)
{
    int i;

    if (!game || !game->map)
        return;
    i = 0;
    while (i < game->lines)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
    game->map = NULL;
}

int	check_enemy(char **map, int lines)
{
	int i;
	int enemies;
	int j;

	i = 0;
	enemies = 0;
	while (i < lines)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0' && map[i][j] != '\r')
		{
			if (map[i][j] == 'X')
				enemies++;
			j++;
		}
		i++;
	}
	if (enemies < 1)
		return (0);
	else
		return (1);
}