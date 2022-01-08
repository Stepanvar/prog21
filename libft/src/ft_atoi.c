/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:28:10 by ccurie            #+#    #+#             */
/*   Updated: 2021/11/15 17:28:10 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *c, long long number, int minus)
{
	if (minus == 1)
	{
		if (-number < -922337203685477580)
			return (0);
		if (-number == -922337203685477580 && *c > '8')
			return (0);
	}
	else
	{
		if (number > 922337203685477580)
			return (-1);
		if (number == 922337203685477580 && *c > '7')
			return (-1);
	}
	return (1);
}

static int	spaces(const char *c)
{
	int		minus;
	long	number;

	number = 0;
	minus = 0;
	while (*c && (*c == ' ' || (*c >= 9 && *c <= 13)))
		c++;
	if (*c && *c == '-')
	{
		minus = 1;
		c++;
	}
	else if (*c && *c == '+')
		c++;
	while (*c && ft_isdigit(*c))
	{
		if (check(c, number, minus) == 0)
			return (0);
		else if (check(c, number, minus) == -1)
			return (-1);
		number = (number * 10) + (*c++) - '0';
	}
	if (minus == 1)
		return (-number);
	return (number);
}

int	ft_atoi(const char *c)
{
	long	number;

	number = spaces(c);
	return (number);
}
