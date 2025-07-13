#include "so_long.h"

int	fd_creator(char *map_file)
{
	int fd;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
    	exit(1);
	return fd;
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