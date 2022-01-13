#include <stdio.h>
#include "unistd.h"
#include "stdlib.h"
#include "fcntl.h"

void	ft_putstr(char *str)
{
	while (*str)
		str += write(1, str, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(const char *str, int start, int end)
{
	int	i;
	int	j;
	char	*sub;

	i = 0;
	j = 0;
	sub = (char *)malloc((end - start)* sizeof(char) + 1);
	if (!sub)
		return (NULL);
	if (end > ft_strlen(str))
		end = ft_strlen(str);
	while (i < start && str[i])
		i++;
	while (i < end && str[i])
		sub[j++] = str[i++];
	sub[j] = '\0';
	return (sub);
}

char	*ft_strchr(const char *str, unsigned char c)
{
	int	i;

	i = -1;
	if (!str)
		return (NULL);
	if ((unsigned char) c == '\0')
		return ((char *)&(str[ft_strlen(str)]));
	while (*(str + ++i))
		if ((unsigned char)*(str + i) == (unsigned char)c)
			return ((char *)(str + i));
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	int		size;
	char	*join;

	i = 0;
	j = 0;
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	join =(char *)malloc(size * sizeof(char) + 1);
	while (str1[i])
	{
		join[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		join[i + j] = str2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_get_line(char **usave, int fd)
{
	char	*str;
	int		size;

	size = BUFFER_SIZE;
	if (!*usave || !ft_strchr(*usave, '\n'))
	{
		while (!ft_strchr(*usave, '\n') && size > 0)
		{
			str = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
			size = read(fd, str, BUFFER_SIZE);
			str[size] = '\0';
			*usave = ft_strjoin(*usave, str);
			free(str);
			str = NULL;
		}
	}
	str = ft_substr(*usave, 0, ft_strchr(*usave, '\n') - *usave + 1);
	*usave = ft_strjoin("", ft_substr(*usave, ft_strchr(*usave, '\n') - *usave + 1, ft_strlen(*usave)));
	if (0 == size)
	{
		free(str);
		free(*usave);
		str = NULL;
		*usave = NULL;
		return (NULL);
	}
	return(str);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*str;

	if (!save)
		save = ft_strjoin("", "");
	str = ft_get_line(&save, fd);
	if (!str)
		return (NULL);
	if ((!*save))
	{
		free(save);
		save = NULL;
		return (str);
	}
	return (str);
}

int main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	*str;

	i = 1;
	fd = 0;
	if (1 == argc)
		return (-1);
	fd = open(argv[1], O_RDWR);
	while (i)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (!str)
			return(1);
		free(str);
		str = NULL;
		i++;
	}
	return (0);
}
