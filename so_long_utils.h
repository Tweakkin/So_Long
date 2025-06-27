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
