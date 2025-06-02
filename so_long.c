#include "so_long.h"

/*void draw_square(void *mlx, void *window, int start_x, int start_y, int color)
{
    for (int x = start_x; x < start_x + 64; x++) {
        for (int y = start_y; y < start_y + 64; y++) {
            mlx_pixel_put(mlx, window, x, y, color);
        }
    }
}*/


int	count_lines(char *buffer)
{
	int	i;
	int	lines = 0;

	i = 0;
	while(buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			lines++;
		i++;
		if (buffer[i] == '\0')
			lines++;
	}
	return (lines);
}

int count_rows(char *buff)
{
	//int rows = 0;
	int i;

	i = 0;
	while (buff[i] != '\n')
	{
		i++;
	}
	if (buff[i] == '\n')
		i--;
	return (i);
}

char **Allocate_map_in_mem(char *buffer, int lines, int rows)
{
	int i;
	char **map;
	int line_counter;

	line_counter = 0;
	i = 0;
	while (line_counter < lines)
	{
		if (buffer[i] == '\n')
		{
			map[line_counter] = malloc(sizeof(char) * rows);
			line_counter++;
		}
		i++;
	}
	return map;
}

int main(void)
{
	int lines, rows;
	int bytes_read;
	char buffer[10000]; 
	char **map;
	int x = 0, y = 0;

	//OPENING READING THE FILE INTO A BUFFER
	int fd = open("./maps/simple.ber", O_RDONLY);
	bytes_read = read(fd, buffer, 10000);
	buffer[bytes_read] = '\0';

	//COUNTING THE ROWS AND LINES OF THE MAP
	lines = count_lines(buffer);
	rows = count_rows(buffer);
	printf("%d\n%d\n", lines, rows);

	//STOCKING THE MAP IN A 2D ARRAY
	map = Allocate_map_in_mem(buffer, lines, rows);

	int yah, yah1;
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
	close(fd);
    return (0);
}