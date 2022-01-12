#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

void	ft_putstr(char *str)
{
	while (*str)
		str += write(1, str, 1);
}

char	*ft_substr(const char *str, int start, int end)
{
	int	i;
	int	j;
	char	*sub;

	i = 0;
	j = 0;
	sub = (char *)malloc(end - start + 1);
	if (!sub)
		return (NULL);
	while (i < start)
		i++;
	while (i < end)
		sub[j++] = str[i++];
	sub[j] = '\0';
	return (sub);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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

char	*ft_strjoin(char *save, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (save[i])
		i++;
	while (str[j])
	{
		save[i + j] = str[j];
		j++;
		save[i + j] = '\0';
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char	*save = NULL;
	int	size;
	int	i;

	i = 1;
	size = 1;
	if (!save)
	{
		while ((!ft_strchr(save, '\n') || i == 1) && size > 0)
		{
			str = (char *)malloc(1 * i + 1);
			if (save)
			{
				str = ft_strjoin(str, save);
				free(save);
				*save = '\0';
			}
			save = (char *)malloc(1 * i + 1);
			*save = '\0';
			save = ft_strjoin(save, str);
			//free(str);
			size = read(fd, str, 1);
			str[size] = '\0';
			save = ft_strjoin(save, str);
			free(str);
			*str = '\0';
			i++;
		}
	}
	if (size <= 0)
	{
		free(save);
		free(str);
		save = NULL;
		str = NULL;
		return (NULL);
	}
	str = ft_substr(save, 0, ft_strchr(save, '\n') - save + 1);
	str[ft_strchr(save, '\n') - save + 1] = '\0';
	save += ft_strlen(str);
	if ((!*save))
	{
		save -= ft_strlen(str);
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
		*str = '\0';
		i++;
	}
	return (0);
}
