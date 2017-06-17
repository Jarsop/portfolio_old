/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 16:48:03 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:55:49 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...)
{
	t_conv	t_mask[TAB_LEN];
	va_list	ap;
	char	*str;

	g_i = 1;
	g_n = 0;
	g_l = -1;
	ft_init_tab(t_mask);
	va_start(ap, format);
	str = ft_wformat(ap, (char*)format, t_mask);
	va_end(ap);
	if (str)
	{
		if (g_n)
			g_i += ft_strlen(g_f);
		else
			g_i = ft_strlen(g_f);
	}
	ft_putstr(str);
	free(str);
	return (g_i);
}
