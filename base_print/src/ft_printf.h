/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccurie <ccurie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 20:20:13 by ccurie            #+#    #+#             */
/*   Updated: 2022/01/08 22:46:01 by ccurie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "unistd.h"
# include "stdarg.h"
# include "stdio.h"

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	hc(void *res, int len);
int	hs(void *res, int len);
int	hp(void *res, int len);
int	hd(void *res, int len);
int	hi(void *res, int len);
int	hu(void *res, int len);
int	hx(void *res, int len);
int	hX(void *res, int len);
#endif