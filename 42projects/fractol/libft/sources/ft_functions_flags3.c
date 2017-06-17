/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_flags3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 00:29:35 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 22:10:14 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "../includes/ft_printf.h"

char	*ft_function_point(const char *format, va_list ap)
{
	int		i;
	char	*str;

	i = 0;
	g_point = 0;
	while (*(format) != '.' && !(ap = NULL))
		++format;
	if (((i = ft_atoi(++format)) && !(g_mask & MASK_NOT))
		|| (g_mask & MASK_D && ft_atoi(g_str)) || ((g_mask & MASK_OO
					|| g_mask & MASK_O) && ft_atoi_base(g_str, "01234567")))
	{
		if (!(g_mask & MASK_S) && !(g_mask & MASK_C) && !(g_mask & MASK_CC)
				&& !(g_mask & MASK_SS))
		{
			ft_help_point(&str, &i);
			if (i > 0)
				return (str);
		}
	}
	else
		return (ft_help_point2());
	return (ft_strdup("\0"));
}

char	*ft_function_0(const char *format, va_list ap)
{
	int		i;
	char	*str;

	ap = NULL;
	str = ft_strdup("\0");
	if (g_mask & MASK_NEG)
		return (str);
	while (*format != '0')
		++format;
	++format;
	if (ft_isalpha(*format))
		return (str);
	while (!ft_isdigit(*(format)))
		++format;
	if ((i = ft_atoi(format)))
		ft_help_0(&str, &i);
	return (str);
}

char	*ft_function_digit(const char *format, va_list ap)
{
	int		i;
	char	*str;

	if ((str = ft_strdup("\0")) && (g_mask & MASK_ZERO || g_mask & MASK_NEG))
		return (str);
	while (!ft_isdigit(*(format)) && !(ap = NULL))
	{
		if (*format == '.')
			return (str);
		++format;
	}
	if (((i = ft_atoi(format)) && (i -= ft_strlen(g_str) + g_n)))
		ft_help_digit(&str, &i);
	if (g_l >= 0 && g_mask & MASK_S && g_mask & MASK_POINT)
	{
		i = ft_atoi(format) - (g_l ? ft_strlen(g_str) : 0);
		if (i > 0)
		{
			free(str);
			str = ft_strnew(i);
			str = ft_memset(str, 32, i);
		}
	}
	g_mask ^= MASK_DIG1;
	return (str);
}
