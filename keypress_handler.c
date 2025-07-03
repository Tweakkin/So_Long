#include "so_long.h"

int	handle_movements(int keycode, t_game *game)
{
	find_player(game, game->map);
	if (keycode == 	119 || keycode == 115)
		move_up_down(keycode, game);
	if (keycode == 100 || keycode == 97)
		move_right_left(keycode, game);
	mlx_clear_window(game->mlx, game->mlx_window);
	display_map(game);
	return (0);
}