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
#define BUFFER_SIZE_2 10000

# ifndef FD_SIZE
#  define FD_SIZE 4096
# endif

#endif