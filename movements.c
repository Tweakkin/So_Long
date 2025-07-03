#include "so_long.h"

void	move_up_down(int keycode, t_game *game)
{
	if ((game->map[game->y_player - 1][game->x_player] == 'C' && keycode == 119) || (game->map[game->y_player + 1][game->x_player] == 'C' && keycode == 115))
		game->collectibles_count++;
	printf("%d", game->collectibles_count);
	if (keycode == 119)
	{
		if (game->map[game->y_player - 1][game->x_player] == '0' || game->map[game->y_player - 1][game->x_player] == 'C')
			game->map[game->y_player - 1][game->x_player] = 'P';
		else if (game->map[game->y_player - 1][game->x_player] == 'E' && game->collectibles_count == game->collectibles_num)
		{
			game->map[game->y_player - 1][game->x_player] = 'P';
			mlx_destroy_window(game->mlx, game->mlx_window);
		}
		else
			return;
	}
	if (keycode == 115)
	{
		if (game->map[game->y_player + 1][game->x_player] == '0' || game->map[game->y_player + 1][game->x_player] == 'C')
			game->map[game->y_player + 1][game->x_player] = 'P';
		else if (game->map[game->y_player + 1][game->x_player] == 'E' && game->collectibles_count == game->collectibles_num)
		{
			game->map[game->y_player + 1][game->x_player] = 'P';
			mlx_destroy_window(game->mlx, game->mlx_window);
		}
		else
			return;
	}
	game->map[game->y_player][game->x_player] = '0';
}

void	move_right_left(int keycode, t_game *game)
{
	if ((game->map[game->y_player][game->x_player + 1] == 'C' && keycode == 100) || (game->map[game->y_player][game->x_player - 1] == 'C' && keycode == 97))
		game->collectibles_count++;
	printf("%d", game->collectibles_count);
	if (keycode == 100)
	{
		if (game->map[game->y_player][game->x_player + 1] == '0' || game->map[game->y_player][game->x_player + 1] == 'C')
			game->map[game->y_player][game->x_player + 1] = 'P';
		else if (game->map[game->y_player][game->x_player + 1] == 'E' && game->collectibles_count == game->collectibles_num)
		{
			game->map[game->y_player][game->x_player + 1] = 'P';
			mlx_destroy_window(game->mlx, game->mlx_window);
		}
		else
			return;
	}
	if (keycode == 97)
	{
		if (game->map[game->y_player][game->x_player - 1] == '0' || game->map[game->y_player][game->x_player - 1] == 'C')
			game->map[game->y_player][game->x_player - 1] = 'P';
		else if (game->map[game->y_player][game->x_player - 1] == 'E' && game->collectibles_count == game->collectibles_num)
		{
			game->map[game->y_player][game->x_player - 1] = 'P';
			mlx_destroy_window(game->mlx, game->mlx_window);
		}
		else
			return;
	}
	game->map[game->y_player][game->x_player] = '0';
}