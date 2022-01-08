/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:20:57 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/08 23:12:00 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main(int argc, char *argv[1])
{
	printf("\t|%d|\n", ft_printf("char = %c, str = %s, int = %d, %x", 'a', "hi dude i'm okay", -2147483647, -1));
	printf("\t|%d|\n", printf("char = %c, str = %s, int = %d, %x", 'a', "hi dude i'm okay", -2147483647, -1));
	return (0);
}
