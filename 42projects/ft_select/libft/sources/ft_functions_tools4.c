/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_tools4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:13:10 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:31:45 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <wchar.h>

char	*ft_getwstringt(const char *format, va_list ap)
{
	wchar_t			*ws;
	int				i;
	unsigned int	wc;
	char			*str;

	i = -1;
	format = NULL;
	ws = va_arg(ap, wchar_t*);
	if (!ws)
		return (ft_strdup("(null)"));
	str = ft_memalloc(1);
	while (ws[++i])
	{
		wc = ws[i];
		str = ft_strwjoin(str, ft_getwschart(wc), 2);
	}
	return (str);
}

char	*ft_function_pc(const char *format, va_list ap)
{
	ap = NULL;
	format = NULL;
	return (ft_strdup("%"));
}

char	*ft_function_dd(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ltoa(va_arg(ap, long)));
}

char	*ft_function_uu(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ultoa(va_arg(ap, unsigned long)));
}

char	*ft_function_oo(const char *format, va_list ap)
{
	format = NULL;
	return (ft_ultoa_base(va_arg(ap, unsigned long), "01234567"));
}
