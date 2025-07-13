#include "so_long.h"

void	move_right_left(int keycode, t_game *game)
{
	int offset;

	offset = 1;
	game->moves_counter++;
	print_moves(game->moves_counter);
	if (keycode == 97)
		offset = -1;
	if (game->map[game->y_player][game->x_player + offset] == 'C')
		game->collected++;
	if (game->map[game->y_player][game->x_player + offset] == 'C' ||game->map[game->y_player][game->x_player + offset] == '0')
	{
		game->map[game->y_player][game->x_player + offset] = 'P';
		game->map[game->y_player][game->x_player] = '0';
	}
	else if (game->map[game->y_player][game->x_player + offset] == 'E' && game->collected == game->collectibles_num)
	{
		game->map[game->y_player][game->x_player + offset] = 'P';
		game->map[game->y_player][game->x_player] = '0';
		handle_closing(game);
	}
	else if (game->map[game->y_player][game->x_player + offset] == 'X')
        handle_closing(game);
}

void	move_up_down(int keycode, t_game *game)
{
	int offset;

	offset = 1;
	game->moves_counter++;
	print_moves(game->moves_counter);
	if (keycode == 119)
		offset = -1;
	if (game->map[game->y_player + offset][game->x_player] == 'C')
		game->collected++;
	if (game->map[game->y_player + offset][game->x_player] == 'C' || game->map[game->y_player + offset][game->x_player] == '0')
	{
		game->map[game->y_player + offset][game->x_player] = 'P';
		game->map[game->y_player][game->x_player] = '0';
	}
	else if (game->map[game->y_player + offset][game->x_player] == 'E' && game->collected == game->collectibles_num)
	{
		game->map[game->y_player + offset][game->x_player] = 'P';
		game->map[game->y_player][game->x_player] = '0';
		handle_closing(game);
	}
	else if (game->map[game->y_player][game->x_player + offset] == 'X')
        handle_closing(game);
}