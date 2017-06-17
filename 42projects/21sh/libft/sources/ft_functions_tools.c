/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 01:04:20 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:29:22 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

char	*ft_function_d(const char *format, va_list ap)
{
	format = NULL;
	return (ft_itoa(va_arg(ap, int)));
}

char	*ft_function_s(const char *format, va_list ap)
{
	char	*s;

	format = NULL;
	if (g_mask & MASK_WILD)
		return (ft_strdup("\0"));
	s = va_arg(ap, char*);
	if (s && g_l <= 0)
		return (ft_strdup(s));
	else if (s && g_l > 0)
		return (ft_strndup(s, g_l));
	else
		return (ft_strdup("(null)"));
}

char	*ft_function_c(const char *format, va_list ap)
{
	char	*str;

	format = NULL;
	str = ft_memalloc(2);
	str[0] = va_arg(ap, int);
	if (!str[0])
	{
		if (*g_z || (g_mask & MASK_SPACE && *(g_z + 1)))
		{
			ft_putstr(g_f);
			ft_putstr(g_z);
			g_i += ft_strlen(g_f) + ft_strlen(g_z);
			ft_putchar(0);
			free(g_f);
			free(g_z);
			g_f = ft_memalloc(1);
			g_z = ft_memalloc(1);
		}
		++g_n;
	}
	return (str);
}

char	*ft_function_o(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ultoa_base(va_arg(ap, unsigned int), "01234567"));
}

char	*ft_function_x(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ultoa_base(va_arg(ap, unsigned int), "0123456789abcdef"));
}
