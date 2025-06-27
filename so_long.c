#include "so_long.h"

int main(int argc, char **argv)
{
	t_game game;
	
	game.map = allocate_fill_map(argv[1]);
	game.lines = count_lines(argv[1]);
	game.width = count_width(game.map);
	
	printf("is map valid : %d\n", is_map_valid(&game));
    return (0);
}