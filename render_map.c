#include "so_long.h"

void	display_map(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == '0')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_wall, j * 64, i * 64);
			}
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_player, j * 64, i * 64);
			else if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_limits, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_collectibles, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_exit, j * 64, i * 64);
			j++;
		}
		i++;
	}
}