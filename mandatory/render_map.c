#include "so_long.h"

void	display_map(t_game *game)
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
            else if (game->map[y][x] == 'E')
                img = game->img_exit;
            else if (game->map[y][x] == 'P')
                img = game->img_player;
            else
                img = game->img_limits;
            mlx_put_image_to_window(game->mlx, game->mlx_window, img, x * 64, y * 64);
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