/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:46:11 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/06 12:48:03 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int	ft_isnum(char c)
{
	if (('0' <= c || c <= '9'))
		return (1);
	else
		return (0);
}

long	ft_atoi(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (str[i] == '-')
	{
		write(1, "-", 1);
		i++;
	}
	while (i < ft_length(str) && ft_isnum(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ft_print_num(int num)
{
	char	c;
	int		rem;

	rem = 0;
	if (num / 10 == 0)
	{
		c = (char) num + '0';
		write(1, &c, 1);
	}
	else
	{
		rem = num % 10;
		c = (char) rem + '0';
		ft_print_num(num / 10);
		write(1, &c, 1);
	}
	return (0);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		write(1, &(str[i]), 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

int	ft_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_int_prints(int i)
{
	printf("10 %10d\n", i);
	printf("-10 %-10d\n", i);
	printf("010 %010d\n", i);
	printf("+10 %+10d\n", i);
	printf(" 10 % 10d\n", i);
	printf("10.3 %10.3d\n", i);
	printf("10 %10d\n", i);
	printf("-+10 %-+10d\n", i);
	printf("-010 %-010d\n", i);
}

void	ft_p_field(void)
{
	int	neg;
	int	pos;

	neg = -15090;
	printf("neg\n");
	ft_int_prints(neg);
	pos = 13678;
	printf("pos\n");
	ft_int_prints(pos);
}

void	ft_field(char *arg)
{
	t_s	s;

	if (!*arg)
		return ;
	s = ft_init_s(s, arg);
	ft_split(s);
}

t_s	ft_init_s(t_s s, char *arg1)
{
	s.minus = 0;
	s.plus = 0;
	s.sharp = 0;
	s.precision = 6;
	s.space = 0;
	s.zero = 0;
	s.width = 10; ////
	s.arg = arg1;
	return (s);
}

char	*ft_strcp(char *dest, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		dest[i] = *str;
		i++;
		str++;
	}
	return (dest);
}	

void	ft_split(t_s s)
{
	char	*str1;

	str1 = "popitka";
	s = ft_handle_flag(s);
	printf("%d", s.minus);
//	s = ft_handle_width(s);
//	ft_handling_justif(s, str1);
//	ft_handle_precision(s, str);
//	ft_handle_length(s, str);
//	ft_handle_format(s, str);
}

t_s	ft_handle_width(t_s s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(10 * sizeof(char));
	while (ft_isnum(*(s.arg)))
	{
		dest[i] = *(s.arg);
		i++;
		(s.arg)++;
	}
	dest[i] = '\0';
	s.width = ft_atoi(dest);
	return (s);
}

t_s	ft_handle_flag(t_s s)
{
	if (*(s.arg) == ' ')
		s.space = 1;
	else if (*(s.arg) == '-')
		s.minus = 1;
	else if (*(s.arg) == '+')
		s.plus = 1;
	else if (*(s.arg) == '#')
		s.sharp = 1;
	else if (*(s.arg) == '0')
		s.zero = '0';
	else
		return (s);
	(s.arg)++;
	return (s);
}

void	ft_handling_justif(t_s s, char *str) //real string
{
	printf("%d", s.minus);
	if (s.minus == 1)
		ft_left_justif(s, str);
	else
		ft_right_justif(s, str);
}

void	ft_right_justif(t_s s, char *str)
{
	char	str1[s.width + 1];
	int		i;

	i = 0;
	while (i < s.width)
	{
		while (i < s.width - ft_length(str))
		{
			str1[i] = '0';
			i++;
		}
		str1[i] = *str;
		i++;
		str++;
	}
	str1[i] = '\0';
	ft_putstr(str1);
}

void	ft_left_justif(t_s s, char *str)
{
	char	str1[s.width + 1];
	int		i;

	i = 0;
	while (i < s.width)
	{
		while (*str)
		{
			str1[i] = *str;
			i++;
			str++;
		}
		str1[i] = '0';
		i++;
	}
	str1[i] = '\0';
	ft_putstr(str1);
}
