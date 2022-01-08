/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:18:08 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:02:11 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;

	i = 0;
	while ((i < n))
	{
		if (((char *)str)[i] == (char)c)
			return ((void *)(&(((char *)str)[i])));
		i++;
	}
	return (NULL);
}
