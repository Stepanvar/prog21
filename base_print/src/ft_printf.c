/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:22:43 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/09 13:15:33 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_num_func(char c, const char *arg)
{
	int	i;

	i = 0;
	while (c != arg[i] && arg[i])
		i++;
	return (i);
}

int	ft_handle_arg(va_list ap, int len, const char *str)
{
	static int	(*fmass[8])(void *, int) = {&hc, &hs, &hp, &hd, &hi,
		&hu, &hx, &hX};
	int			i;
	char		*arg;
	void		*res;

	i = 0;
	arg = "cspdiuxX";
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			if (*(str + 1) == '%')
				str++;
			else
			{
				res = va_arg(ap, void *);
				i = ft_num_func(*(str + 1), arg);
				len = fmass[i](res, len);
				str += 2;
				continue ;
			}
		}
		len += write(1, str, 1);
		str++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	len = ft_handle_arg(ap, len, str);
	va_end(ap);
	return (len);
}
