/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:15:58 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/07 16:18:00 by ccurie           ###   ########.fr       */
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

	buf = ft_substr(str, 0, ft_strchr(str, c) - str + 1);
	return (buf);
}

//char	*ft_check(char *buf, char *str, int size)
//{
//	if (-1 == size)
//	{
//		free(str);
//		free(buf);
//		return (NULL);
//	}
//}

char	*get_next_line(int fd)
{
	int		size;
	static char	*str = NULL;
	char		*buf;

	size = 0;
	if (!str)
	{
		str = (char *)malloc(BUFFER_SIZE + 1);
	
		if (!str)
			return (NULL);
		size = read(fd, str, BUFFER_SIZE);
		str[size + 1] = '\0';
	}
	buf = ft_onesplit(str, '\n');
	if (-1 == size || 0 == size)
	{
		free(str);
		if (0 == size)
			return(buf);
		else
			return (NULL);
	}
	str += ft_strlen(buf) - 1;
	return (buf);
}

 int	main(int argc, char *argv[])
 {
 	int		fd;
 	int		i;
 	char	*str;

 	fd = 0;
 	i = 0;
 	if (argc == 1)
 	{
 		fd = open(argv[1], O_RDONLY);
 		if (-1 == fd)
 			return (-1);
 	}
 	str = get_next_line(fd);
	printf("%s", str);
 	while (i < 10)
 	{
 		str = get_next_line(fd);
		printf("%s", str);
 		i++;
 	}
 	close(fd);
 	return (0);
 }
