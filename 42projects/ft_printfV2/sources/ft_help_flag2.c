/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_flag2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 20:21:18 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 22:02:32 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

void	ft_help_job(va_list ap, char **ftmp, t_conv *t_mask, int i)
{
	if (g_mask & t_mask[i].mask)
		g_z = ft_strwjoin(g_z, t_mask[i].p(*ftmp, ap), 2);
}

void	ft_optimask(char *ftmp)
{
	g_l = 0;
	if (g_mask & MASK_POINT && g_mask & MASK_ZERO && (g_mask & MASK_DIG1))
	{
		g_mask ^= MASK_ZERO;
		g_mask |= MASK_DIG1;
	}
	if (g_mask & MASK_POINT && g_mask & MASK_S)
		ft_pstr(ftmp);
}

void	ft_help_point(char **str, int *i)
{
	*i -= ft_atoi(g_str) < 0 ? ft_strlen(g_str) - 1 : ft_strlen(g_str);
	if (g_mask & MASK_HASH)
		*i += g_mask & MASK_X || g_mask & MASK_XX ? 2 : 0;
	if (*i > 0)
	{
		*str = ft_memset(ft_strnew(*i), 48, *i);
		if (g_mask & MASK_X && g_mask & MASK_HASH)
			*str = ft_strwjoin("0x", *str, 1);
		if (g_mask & MASK_XX && g_mask & MASK_HASH)
			*str = ft_strwjoin("0X", *str, 1);
		g_str = ft_strwjoin(*str, g_str, 1);
		g_point = *i + ft_strlen(g_str);
	}
}

void	ft_help_0(char **str, int *i)
{
	*i -= (g_mask & MASK_D && !ft_atoi(g_str)) || g_n ? ft_strlen(g_str) + 1
		: ft_strlen(g_str);
	*i = g_mask & MASK_POS && ft_atoi(g_str) > 0 ? *i - 1 : *i;
	if (g_mask & MASK_HASH)
		*i -= 2;
	if (*i > 0)
	{
		free(*str);
		*str = ft_strnew(*i);
		*str = ft_memset(*str, 48, *i);
	}
}

void	ft_help_digit(char **str, int *i)
{
	*i = g_p ? *i + 1 : *i;
	*i = g_mask & MASK_POS && ft_atoi(g_str) > 0 ? *i - 1 : *i;
	if (*i > 0)
	{
		free(*str);
		*str = ft_strnew(*i);
		*str = ft_memset(*str, 32, *i);
	}
}
