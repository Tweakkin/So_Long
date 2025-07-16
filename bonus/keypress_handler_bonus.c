#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	find_player(game, game->map);
	if (keycode == 119)
	{
		move_up_down(keycode, game);
		game->player_dir = 'U';
	}
	else if (keycode == 115)
	{
		move_up_down(keycode, game);
		game->player_dir = 'D';
	}
	else if (keycode == 100)
	{
		move_right_left(keycode, game);
		game->player_dir = 'R';
	}
	else if (keycode == 97)
	{
		move_right_left(keycode, game);
		game->player_dir = 'L';
	}
	else if (keycode == 65307)
		handle_closing(game);
	display_map(game);
	return (0);
}

int	handle_closing(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	free_allocated(game);
	exit(0);
}