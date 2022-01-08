/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:44:51 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/06 20:26:57 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (((unsigned char *)s)[++i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char *)s)[i]);
	}	
	if (((unsigned char *)s)[i] == (unsigned char)c)
		return (&((char *)s)[i]);
	return (NULL);
}

static char	*ft_create_newstring(size_t i)
{
	char	*p;

	p = malloc(sizeof(char) * i + 1);
	if (!p)
		return (NULL);
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size <= start)
		return (ft_create_newstring(0));
	if ((len + start) > size)
		len = size - start;
	str = ft_create_newstring(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + (size_t)start];
		i++;
	}
	return (str);
}

void	ft_test_fd(int argc, char *argv[])
{
	int		fd;
	char	buf[11];
	char	buf1[11];

	fd = 0;
	if (1 == argc)
	{
		fd = 0;
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (-1 == fd)
			return ;
	}
	read(fd, buf, 10);
	//buf[11] = '\0';
	printf("%s", buf);
	read(fd, buf1, 10);
	printf("%s", buf1);
	close(fd);
}

int	ft_test_static(void)
{
	static int	i = 2;

	i++;
	return (i);
}

char	**ft_onesplit(char **buf, char c)
{
	int		place;

	place = ft_strchr(buf[0], c) - buf[0];
	buf[1] = ft_substr(buf[0], place, ft_strlen(buf[0]));
	return (buf);
}

void	ft_test_split(char *str)
{
	char	**buf;

	buf = (char **)malloc(100);
	buf[0] = str;
	buf = ft_onesplit(buf, '\n');
	printf("0 %s\n", buf[0]);
	printf("1 %s\n", buf[1]);
}

int	main(int argc, char *argv[])
{
	int	num;

	num = 0;
	//ft_test_fd(argc, argv);
	// while (num < 4)
	// {
	// 	num = ft_test_static();
	// 	printf("%d", num);
	// }
	if (1 == argc)
		return (-1);
	argv[1] = "good\nwork\n";
	ft_test_split(argv[1]);
	return (0);
}
