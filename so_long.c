#include "so_long.h"

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
	
	init_game_data(&game, argv[1]);
	is_map_valid(&game);
    return (0);
}