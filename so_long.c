#include "so_long.h"

int	count_lines(void)
{
	char *buffer;
	int	i;
	int	lines;

	lines = 0;
	buffer = map_into_buffer();
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

char *map_into_buffer(void)
{
    int fd;
    int bytes_read;
    char *buffer;

	buffer = malloc(BUFFER_SIZE_2);
    if (!buffer)
        return NULL;
    fd = fd_creator();
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

int count_rows(char *buff)
{
    int i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    return i;
}

char	**allocate_fill_map(void)
{
	char	**map;
	char	*line;
	int		i;
	int		fd;
	int		lines;

	fd = fd_creator();
	lines = count_lines();
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

int	fd_creator(void)
{
	int fd;

	fd = open("./maps/simple.ber", O_RDONLY);
	if (fd < 0)
    	exit(1);
	return fd;
}

/*int	map_c_p_cheker(void)
{
	char *buffer;

	buffer = map_into_buffer();
}*/

int	is_map_rectangulaire(char **map)
{
	int i;
	int j;
	int temp;

	i = 0;
	temp = -1;
	while (map[i] != NULL)
	{
		j = ft_strlen(map[i]);
		if (j > 0 && map[i][j - 1] == '\n')
		{
			if (map[i][j - 2] == '\r')
			{
				j--;
			}
			j--;
		}
		if (temp != j && temp != -1)
			return 0;
		else
			temp = j;
		i++;
	}
	return 1;
}

int main(void)
{
	char **map;
	int x = 0, y = 0;

	map = allocate_fill_map();
	int idk = is_map_rectangulaire(map);
	printf("%d", idk);

	/*int yah, yah1;
	//creating connection identifier
    void *mlx = mlx_init();
	//setting up the window
    void *Window = mlx_new_window(mlx, 1500, 1000, "PACMANNNN");
	while(x < 64)
	{
		mlx_pixel_put(mlx, Window, x, 64, 0xFF0000);
		while(y<64)
		{
			mlx_pixel_put(mlx, Window, 64, y, 0xFF0000); 
			y++;
		}
		x++;
	}
    //create an image
	void *img = mlx_xpm_file_to_image(mlx, "./sprites/aight_resized.xpm", &yah, &yah1);
	mlx_put_image_to_window(mlx, Window, img, 64, 64);
	//putting the image in window
	//mlx_put_image_to_window(con_iden, Window, img, 0, 0);
	// Window stays open
    mlx_loop(mlx);
	close(fd);*/
    return (0);
}