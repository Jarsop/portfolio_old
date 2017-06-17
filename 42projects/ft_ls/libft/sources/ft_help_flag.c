/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 21:41:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:58:47 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_help_h(va_list ap)
{
	unsigned short	sh;

	if (g_mask & MASK_XX)
	{
		sh = va_arg(ap, unsigned int);
		return (ft_ultoa_base(sh, "0123456789ABCDEF"));
	}
	else
		g_mask ^= MASK_H;
	return (ft_strdup("\0"));
}

char	*ft_help_hh(va_list ap)
{
	unsigned char	sh;
	unsigned short	hu;

	if ((g_mask & MASK_U))
	{
		sh = va_arg(ap, unsigned int);
		return (ft_ultoa(sh));
	}
	else if (g_mask & MASK_UU || g_mask & MASK_DD)
	{
		hu = va_arg(ap, unsigned int);
		return (ft_ultoa(hu));
	}
	else if (g_mask & MASK_XX)
	{
		sh = va_arg(ap, unsigned int);
		return (ft_ultoa_base(sh, "0123456789ABCDEF"));
	}
	else
		g_mask ^= MASK_HH;
	return (ft_strdup("\0"));
}

char	*ft_help_l(va_list ap, const char *format)
{
	unsigned long	ul;

	if ((g_mask & MASK_U) || (g_mask & MASK_UU))
	{
		ul = va_arg(ap, unsigned long);
		return (ft_ultoa(ul));
	}
	if (g_mask & MASK_XX)
	{
		ul = va_arg(ap, unsigned long);
		return (ft_ultoa_base(ul, "0123456789ABCDEF"));
	}
	else if ((g_mask & MASK_U) || (g_mask & MASK_UU))
	{
		ul = va_arg(ap, unsigned long);
		return (ft_ultoa(ul));
	}
	else if (g_mask & MASK_C)
		return (ft_strdupclr(ft_getwchart(format, ap)));
	else if ((g_mask & MASK_S))
		return (ft_strdupclr(ft_getwstringt(format, ap)));
	else
		g_mask ^= MASK_L;
	return (ft_strdup("\0"));
}

char	*ft_help_ll(va_list ap)
{
	unsigned long long	ull;

	if ((g_mask & MASK_U) || (g_mask & MASK_UU))
	{
		ull = va_arg(ap, unsigned long long);
		return (ft_ultoa(ull));
	}
	else if (g_mask & MASK_XX)
	{
		ull = va_arg(ap, unsigned long long);
		return (ft_ultoa_base(ull, "0123456789ABCDEF"));
	}
	else if ((g_mask & MASK_U) || (g_mask & MASK_UU))
	{
		ull = va_arg(ap, unsigned long long);
		return (ft_ultoa(ull));
	}
	else
		g_mask ^= MASK_LL;
	return (ft_strdup("\0"));
}
