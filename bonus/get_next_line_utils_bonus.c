#include "so_long.h"

char	*ft_strdup(const char *str)
{
	size_t	strleng;
	size_t	i;
	char	*newstr;

	if (!str)
		return (NULL);
	i = 0;
	strleng = ft_strlen(str);
	newstr = (char *)malloc(strleng + 1);
	if (!newstr)
		return (NULL);
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*strcopy(const char *src, int dstlen)
{
	char	*line;
	int		i;

	i = 0;
	line = (char *)malloc(dstlen + 2);
	if (!line)
		return (NULL);
	while (i < dstlen)
	{
		line[i] = src[i];
		i++;
	}
	if (src[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}