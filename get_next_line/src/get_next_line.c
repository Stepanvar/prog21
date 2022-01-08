/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:58 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/08 19:10:45 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "get_next_line.h"

char	*ft_onesplit(char *str, char c)
{
	int		i;
	char	*buf;

	i = 0;
	i = (ft_strchr(str, c) - str + 1);
	buf = ft_substr(str, 0, ft_strchr(str, c) - str + 1);
	printf("\n|%d|", i);
	printf("|buf %s|", buf);
	buf[i + 1] = '\0';
	return (buf);
}

char	*get_next_line(int fd)
{
	int			size;
	static char	*str = NULL;
	char		*buf;

	size = 0;
	if (!str)
	{
		str = (char *)malloc(BUFFER_SIZE + 1);
		if (!str)
			return (NULL);
		size = read(fd, str, BUFFER_SIZE);
	}
	buf = ft_onesplit(str, '\n');
	if (0 == size)
	{
		str = NULL;
		return (buf);
	}
	str += ft_strlen(buf);
	return (buf);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*str;

	fd = 0;
	i = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (-1 == fd)
			return (-1);
	}
	str = get_next_line(fd);
	printf("%s", str);
	while (i < 4)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	close(fd);
	return (0);
}
