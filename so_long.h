#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char **map;
	int lines;
	int width;
	char *filename;
	int	x_player;
	int y_player;
	void *mlx;
	void *mlx_window;
	void *img_player;
	int img_width;
	int img_height;
}t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*strcopy(const char *src, int dstlen);
int	ft_strlen(const char *str);
int	check_map_rectangular(char **map);
int	fd_creator(char *map_file);
char	**allocate_fill_map(char *map_file);
char *map_into_buffer(char *map_file);
int	count_lines(char *map_file);
char *map_into_buffer(char *map_file);
int count_width(char **buff);
int check_map_walls(char **map, int lines, int rows);
int	check_middle_lines(char **map, int lines, int rows);
int check_exit(char **map, int lines);
int check_player(char **map, int lines);
int check_collectibles(char **map, int lines);
int check_invalid_char(char **map, int lines);
void	is_map_valid(t_game *game);
void check_map_elements(t_game *game, char **map, int lines);
char	**allocate_fill_map(char *map_file);
int	check_filename(char *filename);
void	init_game_data(t_game *game, char *filepath);
void	ft_putstr(char *s);
void exit_error(t_game *game, char *msg);
char	*ft_strcpy(char *dest, const char *src);
char **copy_map(char **src, int lines, int width);
int	check_valid_path(t_game *game);
void	find_player(t_game *game, char **map);
void	floodfill(char **map, int x, int y);
int	is_path_reachable(char **map, int lines, int width);

#define BUFFER_SIZE_2 10000
# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif

#endif