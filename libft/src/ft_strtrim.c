/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:28:08 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:04:33 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	end;
	char	*str;

	str = NULL;
	if (s1 != 0 && set != 0)
	{
		index = 0;
		end = ft_strlen(s1);
		while (s1[index] && ft_strchr(set, s1[index]) != 0)
			index++;
		while (end != index && ft_strchr(set, s1[end - 1]) != 0)
			end--;
		str = ft_substr(s1, index, end - index);
	}
	return (str);
}
