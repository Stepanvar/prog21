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
	char	*sub;

	i = 0;
	sub = (char *)malloc(end - start);
	if (!sub)
		return (NULL);
	while (i < start)
		i++;
	while (i < end)
		*sub = str[i++];
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
	}
	return (save);
}

char	*get_next_line(int fd)
{
	char	*str;
	static char	*save = NULL;
//	int	size;
	int	i;

	i = 2;
//	size = 0;
	if (!save)
	{
		while (!ft_strchr(save, '\n') || i == 2)
		{
			str = (char *)malloc(10 + 1);
			read(fd, str, 10);
			save = (char *)malloc((10 + 1) * i);
			save = ft_strjoin(save, str);
			free(str);
			i++;
		}
	}
//	save = ft_strjoin(save, str);
	str = ft_substr(save, 0, ft_strchr(save, '\n') - save + 1);
	return (str);
}

int main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	*str;

	i = 0;
	fd = 0;
	if (1 == argc)
		return (-1);
	fd = open(argv[1], O_RDWR);
	while (i < 1)
	{
		str = get_next_line(fd);
		ft_putstr(str);
		free(str);
		i++;
	}

}
