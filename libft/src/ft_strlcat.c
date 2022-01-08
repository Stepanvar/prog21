/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:43:41 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:03:44 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	src_l;
	size_t	i;

	i = 0;
	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (size == 0)
		return (src_l);
	if (size < dst_l)
		return (src_l + size);
	else
	{
		while (src[i] && dst_l + i < size)
		{
			dst[dst_l + i] = src[i];
			i++;
		}
		if (dst_l + i == size && dst_l < size)
			dst[dst_l + i - 1] = '\0';
		else
			dst[dst_l + i] = '\0';
		return (src_l + dst_l);
	}
}
