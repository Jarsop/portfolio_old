/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 01:25:46 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:26:41 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

char	*ft_function_hashtag(const char *format, va_list ap)
{
	char	*str;

	ap = NULL;
	format = NULL;
	str = ft_strdup("\0");
	if (g_save && (g_save[2] == '0' || g_save[1] == '0') && !(g_mask & MASK_P))
		return (str);
	if (g_mask & MASK_X || g_mask & MASK_P)
		str = ft_strwjoin(str, "0x", 0);
	else if (g_mask & MASK_XX)
		str = ft_strwjoin(str, "0X", 0);
	else if (g_mask & MASK_O || g_mask & MASK_OO)
		str = ft_strwjoin(str, "0", 0);
	return (str);
}

char	*ft_function_fspace(const char *format, va_list ap)
{
	char	*str;
	va_list	cpy;
	int		l;

	format = NULL;
	va_copy(cpy, ap);
	l = va_arg(cpy, long long);
	str = ft_strdup("\0");
	if (l >= 0 && (g_mask & MASK_D || g_mask & MASK_DD || g_mask & MASK_I)
			&& (!(g_mask & MASK_POS) && (!(g_mask & MASK_DIG1)
					|| g_mask & MASK_ZERO)))
	{
		free(str);
		str = ft_strdup(" ");
	}
	return (str);
}

char	*ft_function_fpos(const char *format, va_list ap)
{
	char	*str;
	va_list	cpy;
	int		l;

	format = NULL;
	va_copy(cpy, ap);
	l = va_arg(cpy, long long);
	if ((l >= 0) && (g_mask & MASK_D || g_mask & MASK_DD || g_mask & MASK_I))
		str = ft_strdup("+");
	else
		str = ft_strdup("\0");
	va_end(cpy);
	return (str);
}

char	*ft_function_fneg(const char *format, va_list ap)
{
	char	*str;
	int		i;

	ap = NULL;
	i = ft_strlen(g_str);
	if (g_mask & MASK_POINT && !(g_mask & MASK_S))
		i = g_point ? g_point - 1 : g_point;
	if (g_mask & MASK_POS && ft_atoi(g_str) > 0)
		++i;
	str = ft_strdup("\0");
	while (*(format) && (*format == '0' || *format == '-'
				|| !ft_isdigit(*(format))))
	{
		if (*format == '.')
			return (str);
		++format;
	}
	if ((i = ft_atoi(format) - i) > 0)
	{
		free(str);
		str = ft_strnew(i);
		str = ft_memset(str, 32, i);
	}
	return (str);
}

char	*ft_function_h(const char *format, va_list ap)
{
	short			h;
	unsigned short	sh;

	format = NULL;
	if ((g_mask & MASK_D) || (g_mask & MASK_I))
	{
		h = va_arg(ap, int);
		return (ft_itoa(h));
	}
	else if ((g_mask & MASK_O) || (g_mask & MASK_OO))
	{
		sh = va_arg(ap, unsigned int);
		return (ft_ultoa_base(sh, "01234567"));
	}
	else if (g_mask & MASK_X)
	{
		sh = va_arg(ap, unsigned int);
		return (ft_ultoa_base(sh, "0123456789abcdef"));
	}
	else
		return (ft_strdupclr(ft_help_h(ap)));
}
