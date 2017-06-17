/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_tools2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 01:11:54 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:30:05 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_function_xx(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ultoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
}

char	*ft_function_u(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ultoa(va_arg(ap, unsigned int)));
}

char	*ft_function_p(const char *format, va_list ap)
{
	char	*str;

	format = NULL;
	str = ft_ultoa_base(va_arg(ap, unsigned long),
				"0123456789abcdef");
	return (str);
}

char	*ft_function_a(const char *format, va_list ap)
{
	ap = NULL;
	format = NULL;
	return (ft_strdup("\0"));
}

char	*ft_function_wild(const char *format, va_list ap)
{
	format = NULL;
	g_mask ^= MASK_WILD;
	va_arg(ap, int);
	return (ft_strdup("\0"));
}
