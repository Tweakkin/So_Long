#include "so_long.h"

int	count_lines(char *map_file)
{
	char *buffer;
	int	i;
	int	lines;

	lines = 0;
	buffer = map_into_buffer(map_file);
	i = 0;
	while(buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			lines++;
		i++;
	}
	if (i > 0 && buffer[i - 1] != '\n')
		lines++;

	free(buffer);
	return (lines);
}

int count_width(char **buff)
{
    int i = 0;
    while (buff[0][i] != '\r' && buff[0][i] != '\n' && buff[0][i] != '\0')
        i++;
    return i;
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write (1, s, ft_strlen(s));
}

void exit_error(t_game *game, char *msg)
{
	int	i;

	i = 0;
	if (game && game->map)
	{
		while (i < game->lines)
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	ft_putstr(msg);
	exit(1);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}