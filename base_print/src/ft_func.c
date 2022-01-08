/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:22:54 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/08 23:13:59 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hc(void *res, int len)
{
	char	*c;

	c = (char *) res;
	write(1, &c, 1);
	return (++len);
}

int	hs(void *res, int len)
{
	char	*str;

	str = (char *) res;
	if (!str)
		return (len += write(1, "(null)", 6));
	while (*(str))
		len += write(1, str++, 1);
	return (len);
}

int	hp(void *res, int len)
{
	return (0);
}

int	ft_putnbr(int num, int len)
{
	if (num < 0)
	{
		len += ft_putchar('-');
		if (num == -2147483648)
		{
			len += (write(1, "2147483648", 10));
			return (len);
		}
		num *= -1;
	}
	if (num >= 10)
		len = ft_putnbr(num / 10, len);
	len += ft_putchar(num % 10 + 48);
	return (len);
}

int	ft_uns_int(unsigned int num, int len)
{
	if (num >= 10)
		len = ft_uns_int(num / 10, len);
	len += ft_putchar(num % 10 + 48);
	return (len);
}

int	hd(void *res, int len)
{
	return (ft_putnbr(*((int *)&res), len));
}

int	hi(void *res, int len)
{
	return (ft_putnbr(*((int *)&res), len));
}

int	hu(void *res, int len)
{
	return (ft_uns_int(*((unsigned int *)&res), len));
}

int	ft_16_int(unsigned int num, int len, char *base)
{
	if (num >= 16)
		len = ft_16_int(num / 16, len, base);
	len += ft_putchar(base[num % 16]);
	return (len);
}

int	hx(void *res, int len)
{	
	return (ft_16_int(*((unsigned int *)&res), len, "0123456789abcdef"));
}

int	hX(void *res, int len)
{
	return (ft_16_int(*((unsigned int *)&res), len, "0123456789ABCDEF"));
}
