/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 12:47:14 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/16 15:00:11 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static int	ft_count_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		negativ;

	if (n < 0)
		negativ = -1;
	else
		negativ = 1;
	len = ft_count_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (--len >= 0)
	{
		if (n < 0)
			str[len] = n % 10 * -1 + '0';
		else
			str[len] = n % 10 + '0';
		n /= 10;
	}
	if (negativ == -1)
		str[0] = '-';
	return (str);
}
