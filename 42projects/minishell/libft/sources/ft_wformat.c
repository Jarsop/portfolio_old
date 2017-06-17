/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:03:42 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/16 14:39:48 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_iszero(char *ftmp)
{
	if (*(ftmp - 1) && (ft_isdigit(*(ftmp - 1)) || *(ftmp - 1) == '-'
			|| *(ftmp + 1) == '-' || *(ftmp - 1) == '.' || *(ftmp + 1) == '.'))
		return (0);
	else
		return (1);
}

unsigned long	ft_popmask(t_conv *t_mask, char **ftmp)
{
	int		i;
	char	*tmp;

	g_mask = 0;
	i = -1;
	tmp = ft_strndup(*ftmp, ft_strconv(*ftmp));
	g_len = ft_strlen(tmp);
	while (++i < TAB_LEN)
	{
		if (ft_strstr(tmp, t_mask[i].conv))
		{
			if (i == 17 && ft_iszero(ft_strstr(tmp, t_mask[i].conv)))
				g_mask |= t_mask[i].mask;
			else if (i != 17)
				g_mask |= t_mask[i].mask;
			if (i >= LEN_CONV_MIN)
				return (ft_help_pop(t_mask, &tmp));
		}
	}
	free(tmp);
	return (g_mask);
}

int				ft_pop_g_str(t_conv *t_mask, va_list ap, char *ftmp, int f)
{
	int		i;
	int		st;

	st = -1;
	if (f)
		free(g_str);
	i = 17;
	if ((g_mask & MASK_HASH) && !(g_mask & MASK_ZERO) && !(st = 0))
		g_str = ft_strdupclr(t_mask[0].p(ftmp, ap));
	else
		g_str = ft_strdup("\0");
	while (++i < LEN_CONV_MAX)
	{
		if (g_mask & t_mask[i].mask)
		{
			g_str = ft_strwjoin(g_str, t_mask[i].p(ftmp, ap), 2);
			g_save = g_str;
			if (g_mask & MASK_L || g_mask & MASK_LL || g_mask & MASK_H
					|| g_mask & MASK_HH)
				break ;
		}
	}
	if (g_mask & MASK_NOT)
		g_str = ft_strwjoin(g_str, ft_function_pc(ftmp, ap), 2);
	return (st);
}

char			*ft_tojob(va_list ap, char **ftmp, t_conv *t_mask)
{
	int		i;

	g_z = ft_strdup("\0");
	ft_optimask(*ftmp);
	if (g_mask & MASK_P)
		g_mask |= MASK_HASH;
	i = ft_pop_g_str(t_mask, g_cpy, *ftmp, 0);
	while (++i < 18)
		ft_help_job(ap, ftmp, t_mask, i);
	ft_pop_g_str(t_mask, ap, *ftmp, 1);
	if (g_mask & MASK_NOT && g_mask & MASK_NEG && !g_p)
		g_str = ft_strwjoin("%", ft_function_fneg(*ftmp, ap), 1);
	else if (g_mask & MASK_NEG && !g_p)
		g_str = ft_strwjoin(g_str, ft_function_fneg(*ftmp, ap), 2);
	if (!g_p || (g_mask & MASK_NOT))
	{
		g_z = ft_strwjoin(g_z, g_str, 0);
		ft_patch();
		free(g_str);
	}
	else
		free(g_str);
	g_f = ft_strwjoin(g_f, g_z, 2);
	*ftmp += g_len - 1;
	return (g_f);
}

char			*ft_wformat(va_list ap, const char *format, t_conv *t_mask)
{
	char			*ftmp;
	char			*s;

	g_f = ft_memalloc(1);
	ftmp = ft_strdup(format);
	s = ftmp;
	while (*(ftmp))
	{
		if (*ftmp == '%' && *(ftmp++))
		{
			va_copy(g_cpy, ap);
			g_mask = ft_popmask(t_mask, &ftmp);
			if (g_mask && !(g_p = 0))
				g_f = ft_tojob(ap, &ftmp, t_mask);
			else
				--ftmp;
			va_end(g_cpy);
		}
		else if (*ftmp != '%')
			g_f = ft_strwnjoin(g_f, ftmp, 1, 0);
		++ftmp;
	}
	free(s);
	return (g_f);
}
