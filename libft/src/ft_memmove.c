/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:40:06 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:02:27 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ch_dest;
	const char	*ch_src;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ch_dest = (char *)dest;
	ch_src = (const char *)src;
	if (ch_dest < ch_src)
	{
		while (i < n)
		{
			ch_dest[i] = ch_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i--)
			ch_dest[i] = ch_src[i];
	}
	return (dest);
}
