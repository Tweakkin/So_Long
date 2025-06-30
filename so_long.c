#include "so_long.h"

void	mlx_start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->width * 64, game->lines * 64, "so_long");
	if (!game->mlx_window)
		exit_error(game, "Error: The window failed to create");
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm", &game->img_width, &game->img_height);
	if (!game->img_player)
   	 exit_error(game, "Error: failed to load player image");
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_player, 3, 5);
	mlx_loop(game->mlx);
}

void	init_game_data(t_game *game, char *filepath)
{
	game->filename = filepath;
	game->map = allocate_fill_map(filepath);
	game->lines = count_lines(filepath);
	game->width = count_width(game->map);
}

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc != 2)
		exit_error(NULL, "Error : not enough arguments");
	init_game_data(&game, argv[1]);
	is_map_valid(&game);
	mlx_start_game(&game);
    return (0);
}