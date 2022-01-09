/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:20:57 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/09 12:50:37 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(int argc, char *argv[1])
{
	char	*str;
	int	i = 10000000;
	
	str = (char *)malloc(10000000);
	while (i > 0)
	{
		if (i % 10000000 == 1 || i % 10000000 == 9999999)
		{
			printf("\t|%d|\n", ft_printf("char = %c, str = %s, int = %d, %x, addr = %p", 'a', "hi dude i'm okay", -2147483647, -1, (void *)str));
			printf("\t|%d|\n", printf("char = %c, str = %s, int = %d, %x, addr = %p", 'a', "hi dude i'm okay", -2147483647, -1, (void *)str));
		}
		i--;
		str++;
	}
	free(str);
	return (0);
}
