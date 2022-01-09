/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:58 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/09 18:25:32 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "get_next_line.h"

char	*ft_onesplit(char *str, char c)
{
	char	*buf;

	buf = ft_strchr(str, c);
	return (buf);
}

char	*get_next_line(int fd)
{
	int			size;
	static char	*buf = NULL;
	char		*str;
	int			i;

	i = 0;
	size = 0;
	if (!buf)
	{
		buf = (char *)malloc(BUFFER_SIZE + 2);
		buf[0] = '\0';
		size = read(fd, (++buf), BUFFER_SIZE);
		buf[size + 1] = '\0';
	}
	str = ft_substr(buf, 0, ft_strchr(buf, '\n') - buf + 1);
	buf += ft_strlen(str);
	if ((BUFFER_SIZE == size && !*buf) || (0 == size && !*str))
	{
		while (*(buf - 1))
			buf--;
		free(--buf);
		return (buf);
	}
	return (str);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	char	*str;

	fd = 0;
	i = 0;
	if (1 == argc)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd)
		return (-1);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	while (str)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
	return (0);
}
