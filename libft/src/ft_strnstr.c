/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:07:44 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:04:25 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = (char *)big;
	if (!*little)
		return (str);
	while (str[i] && i < len)
	{
		if (str[i] == little[0])
		{
			j = 0;
			while (str[i + j] == little[j] && i + j < len)
			{
				if (!little[j + 1])
					return (&str[i]);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
