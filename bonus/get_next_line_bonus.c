#include "so_long.h"

size_t	allocate_buff(int fd, char **buff)
{
	size_t	fdlen;

	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!*buff)
		return (0);
	fdlen = read(fd, *buff, BUFFER_SIZE);
	if (fdlen <= 0)
	{
		free(*buff);
		*buff = NULL;
		return (0);
	}
	(*buff)[fdlen] = '\0';
	return (fdlen);
}

char	*create_line(char *buff)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (i > j)
	{
		line[j] = buff[j];
		j++;
	}
	if (buff[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	return (line);
}

void	re_adjust_buff(char **buff)
{
	int	i;
	int	j;

	i = 0;
	while ((*buff)[i] != '\0' && (*buff)[i] != '\n')
		i++;
	if ((*buff)[i] == '\n')
		i++;
	j = 0;
	while ((*buff)[i] != '\0')
	{
		(*buff)[j] = (*buff)[i];
		i++;
		j++;
	}
	(*buff)[j] = '\0';
}

char	*get_next_line(int fd)
{
	static char		*buff[FD_SIZE];
	char			*line;

	if (fd < 0 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buff[fd])
	{
		if (allocate_buff(fd, &buff[fd]) == 0)
			return (NULL);
	}
	line = create_line(buff[fd]);
	if (line != NULL)
		re_adjust_buff(&buff[fd]);
	if (buff[fd][0] == '\0')
	{
		free(buff[fd]);
		buff[fd] = NULL;
	}
	return (line);
}