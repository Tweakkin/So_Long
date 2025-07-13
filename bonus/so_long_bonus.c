#include "so_long.h"

void	mlx_start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->width * 64, game->lines * 64, "so_long");
	if (!game->mlx_window)
		exit_error(game, "Error: The window failed to create");
	game->img_player = mlx_xpm_file_to_image(game->mlx, "./sprites/santa_standing.xpm", &game->img_width, &game->img_height);
	if (!game->img_player)
   	 exit_error(game, "Error: failed to load player image");
	game->img_player_right = mlx_xpm_file_to_image(game->mlx, "./sprites/santa_right.xpm", &game->img_width, &game->img_height);
	if (!game->img_player_right)
   	 exit_error(game, "Error: failed to load player heading right image");
	game->img_player_left = mlx_xpm_file_to_image(game->mlx, "./sprites/santa_left.xpm", &game->img_width, &game->img_height);
	if (!game->img_player_left)
   	 exit_error(game, "Error: failed to load player heading left image");
	game->img_wall = mlx_xpm_file_to_image(game->mlx, "./sprites/snow.xpm", &game->img_width, &game->img_height);
	if (!game->img_wall)
   		exit_error(game, "Error: failed to load map image");
	game->img_limits = mlx_xpm_file_to_image(game->mlx, "./sprites/tree.xpm", &game->img_width, &game->img_height);
	if (!game->img_limits)
   		exit_error(game, "Error: failed to load map limits image");
	game->img_collectibles = mlx_xpm_file_to_image(game->mlx, "./sprites/gift.xpm", &game->img_width, &game->img_height);
	if (!game->img_collectibles)
   		exit_error(game, "Error: failed to load collectibles image");
	game->img_closed_exit = mlx_xpm_file_to_image(game->mlx, "./sprites/closed_door.xpm", &game->img_width, &game->img_height);
	if (!game->img_closed_exit)
   		exit_error(game, "Error: failed to load closed exit image");
	game->img_opened_exit = mlx_xpm_file_to_image(game->mlx, "./sprites/opened_door.xpm", &game->img_width, &game->img_height);
	if (!game->img_opened_exit)
   		exit_error(game, "Error: failed to load opened exit image");
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "./sprites/enemy.xpm", &game->img_width, &game->img_height);
	if (!game->img_enemy)
   		exit_error(game, "Error: failed to load enemy image");
	display_map(game);
	mlx_key_hook(game->mlx_window, handle_keypress, game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->mlx_window, 17, 17, handle_closing, game);
	mlx_loop(game->mlx);
}

void	init_game_data(t_game *game, char *filepath)
{
	game->filename = filepath;
	game->map = allocate_fill_map(filepath);
	game->enemy_map = allocate_fill_map(filepath);
	game->lines = count_lines(filepath);
	game->width = count_width(game->map);
	game->collected = 0;
	game->collectibles_num = collectibles_counter(game);
	game->moves_counter = 0;
	game->frame = 0;
	game->enemy_visiblity = 0;
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