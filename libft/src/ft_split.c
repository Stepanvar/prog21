/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:37:24 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:06:20 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include "stdlib.h"

static size_t	ft_nbr_word(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != c && *str != '\0')
			count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static void	ft_free(char **mem)
{
	int	i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		i++;
	}
	free(mem);
}

static char	**ft_real_split(char const *str, char c)
{
	char	**arr;
	int		i;
	int		nmb;

	if (!str)
		return (NULL);
	i = 0;
	nmb = ft_nbr_word(str, c);
	arr = (char **)ft_calloc(nmb + 1, sizeof(char *));
	if (!arr)
		return (0);
	while (i < nmb)
	{
		arr[i] = ft_substr(str, 0, (ft_strchr(str, c)) - str);
		if (!arr[i++])
		{
			ft_free(arr);
			return (NULL);
		}
		str += (ft_strchr(str, c)) - str + 1;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = ft_real_split(s, c);
	if (!str)
		return (NULL);
	return (str);
}
