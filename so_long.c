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

char *map_into_buffer(char *map_file)
{
    int fd;
    int bytes_read;
    char *buffer;

	buffer = malloc(BUFFER_SIZE_2);
    if (!buffer)
        return NULL;
    fd = fd_creator(map_file);
    bytes_read = read(fd, buffer, BUFFER_SIZE_2 - 1);
    if (bytes_read < 0)
    {
        close(fd);
        free(buffer);
        exit(1);
    }
    buffer[bytes_read] = '\0';
    close(fd);
    return buffer;
}

int count_width(char **buff)
{
    int i = 0;
    while (buff[0][i] != '\r' && buff[0][i] != '\n' && buff[0][i] != '\0')
        i++;
    return i;
}

char	**allocate_fill_map(char *map_file)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;
	int		lines;

	fd = fd_creator(map_file);
	lines = count_lines(map_file);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	fd_creator(char *map_file)
{
	int fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
    	exit(1);
	return fd;
}

int main(int argc, char **argv)
{
	t_game game;
	

	game.map = allocate_fill_map(argv[1]);
	game.lines = count_lines(argv[1]);
	game.width = count_width(game.map);

	printf("is map valid : %d\n", is_map_valid(game.map, game.lines, game.width));
    return (0);
}