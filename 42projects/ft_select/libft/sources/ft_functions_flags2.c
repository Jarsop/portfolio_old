/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_flags2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 01:26:39 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:59:34 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <wchar.h>

char	*ft_function_hh(const char *format, va_list ap)
{
	char			hh;
	unsigned char	sh;

	format = NULL;
	if ((g_mask & MASK_D) || (g_mask & MASK_I))
	{
		hh = va_arg(ap, int);
		return (ft_itoa(hh));
	}
	else if ((g_mask & MASK_O))
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
		return (ft_strdupclr(ft_help_hh(ap)));
}

char	*ft_function_l(const char *format, va_list ap)
{
	long			l;
	unsigned long	ul;

	if ((g_mask & MASK_D) || (g_mask & MASK_DD) || (g_mask & MASK_I))
	{
		l = va_arg(ap, long);
		return (ft_ltoa(l));
	}
	else if ((g_mask & MASK_O) || (g_mask & MASK_OO))
	{
		ul = va_arg(ap, unsigned long);
		return (ft_ultoa_base(ul, "01234567"));
	}
	else if (g_mask & MASK_X)
	{
		ul = va_arg(ap, unsigned long);
		return (ft_ultoa_base(ul, "0123456789abcdef"));
	}
	else
		return (ft_strdupclr(ft_help_l(ap, format)));
}

char	*ft_function_ll(const char *format, va_list ap)
{
	long long			ll;
	unsigned long long	ull;

	format = NULL;
	if ((g_mask & MASK_D) || (g_mask & MASK_DD) || (g_mask & MASK_I))
	{
		ll = va_arg(ap, long long);
		return (ft_ltoa(ll));
	}
	else if ((g_mask & MASK_O) || (g_mask & MASK_OO))
	{
		ull = va_arg(ap, unsigned long long);
		return (ft_ultoa_base(ull, "01234567"));
	}
	else if (g_mask & MASK_X)
	{
		ull = va_arg(ap, unsigned long long);
		return (ft_ultoa_base(ull, "0123456789abcdef"));
	}
	else
		return (ft_strdupclr(ft_help_ll(ap)));
}

char	*ft_function_j(const char *format, va_list ap)
{
	g_mask |= MASK_LL;
	g_mask ^= MASK_J;
	return (ft_strdupclr(ft_function_ll(format, ap)));
}

char	*ft_function_z(const char *format, va_list ap)
{
	g_mask |= MASK_LL;
	g_mask ^= MASK_Z;
	return (ft_strdupclr(ft_function_ll(format, ap)));
}
