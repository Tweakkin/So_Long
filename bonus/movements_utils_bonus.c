#include "so_long.h"

int	collectibles_counter(t_game *game)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < game->lines)
	{
		j = 0;
		while(j < game->width)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}