#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*strcopy(const char *src, int dstlen);
int	ft_strlen(const char *str);
int	check_map_rectangulaire(char **map);
int	fd_creator(char *map_file);
char	**allocate_fill_map(char *map_file);
int	count_lines(char *map_file);
char *map_into_buffer(char *map_file);
int count_width(char **buff);
int check_map_walls(char **map, int lines, int rows);
int	check_middle_lines(char **map, int lines, int rows);
int check_exit(char **map, int lines);
int check_player(char **map, int lines);
int check_collectibles(char **map, int lines);
int check_invalid_char(char **map, int lines);
int	is_map_valid(char **map, int lines, int width);
int check_map_elements(char **map, int lines);

#define BUFFER_SIZE_2 10000
# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif

typedef struct s_game
{
	char **map;
	int lines;
	int width;
}t_game;

#endif