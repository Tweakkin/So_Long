#include "so_long.h"

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
	}
    if (i > 0 && buffer[i - 1] != '\n')
        lines++;
	return (lines);
}

int count_rows(char *buff)
{
    int i = 0;
    while (buff[i] != '\n' && buff[i] != '\0')
        i++;
    return i;
}

char **Allocate_map_in_mem(char *buffer, int lines, int rows)
{
	char **map;
	int line_counter;

	line_counter = 0;
	map = malloc(sizeof(char *) * lines);
	if (!map)
		return (NULL);
	while (line_counter < lines)
	{
		if (*buffer == '\n' || *buffer == '\0')
		{
			map[line_counter] = malloc(sizeof(char) * (rows + 2));
			if (!map[line_counter])
				return (NULL);
			line_counter++;
		}
		if (*buffer == '\0')
			break;
		buffer++;
	}
	return map;
}

void    Filling_up_an_allocated(char *buffer, char **allocated, int lines, int rows)
{
  int lines_counter;
  int rows_counter;
  
  lines_counter = 0;
  rows_counter = 0;
  while(lines_counter < lines)
  {
    while (rows_counter < rows)
    {
      allocated[lines_counter][rows_counter] = *buffer;
	  if (*buffer == '\0')
		break;
      buffer++;
      rows_counter++;
    }
	if (*buffer == '\n')
        allocated[lines_counter][rows_counter++] = *buffer++;
	allocated[lines_counter][rows_counter] = '\0';
    rows_counter = 0;
    lines_counter++;
	}
}

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
		printf("Line %d: length %d [%s]\n", i, j, map[i]);
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
	int bytes_read;
	char buffer[BUFFER_SIZE_2]; 
	char **map;
	int x = 0, y = 0;

	//OPENING READING THE FILE INTO A BUFFER
	int fd = open("./maps/simple.ber", O_RDONLY);
	bytes_read = read(fd, buffer, 10000);
	buffer[bytes_read] = '\0';

	int lines = count_lines(buffer);
	close(fd);
	fd = open("./maps/simple.ber", O_RDONLY);

	map = malloc(sizeof(char *) * (lines + 1));
	char *line;
	int i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	int idk = is_map_rectangulaire(map);
	printf("\n%d", idk);
	printf("%d", ft_strlen("yahya"));
	//printf("%s%s", map[0], map[1]);

	//COUNTING THE ROWS AND LINES OF THE MAP
	//lines = count_lines(buffer);
	//rows = count_rows(buffer);
	//printf("%d\n%d\n", lines, rows);

	//ALLOCATING THE MAP IN A 2D ARRAY
	//map = Allocate_map_in_mem(buffer, lines, rows);
	
	//FILLING UP THE 2D ARRAY
	//Filling_up_an_allocated(buffer, map, lines, rows);


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