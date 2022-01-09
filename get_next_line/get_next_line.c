/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:58 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/09 16:53:14 by ccurie           ###   ########.fr       */
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
	static char	*buf = "\0";
	char		*str;
	int			i;

	i = 0;
	size = 0;
	if (!(*buf))
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
	}
	str = ft_substr(buf, 0, ft_strchr(buf, '\n') - buf + 1);
	buf += ft_strlen(str);
	return (str);
}

// int	main(int argc, char *argv[])
// {
// 	int		fd;
// 	int		i;
// 	char	*str;

// 	fd = 0;
// 	i = 0;
// 	if (1 == argc)
// 		return (-1);
// 	fd = open(argv[1], O_RDONLY);
// 	if (-1 == fd)
// 		return (-1);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	while (*str)
// 	{
// 		str = get_next_line(fd);
// 		printf("%s", str);
// 		i++;
// 	}
// 	close(fd);
// 	return (0);
// }
