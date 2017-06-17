/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:29:46 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:56:45 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_patch_pz(void)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (g_z[i] != '0' && g_z[i + 1])
		++i;
	if (g_z[i + 1])
	{
		s = i;
		while (g_z[i] != '-')
			++i;
		ft_chrswap(&g_z[s], &g_z[i]);
	}
}

static void	ft_patch_to_patch(int c)
{
	int		i;

	i = 0;
	if (c)
	{
		if (g_z[i] == '+')
		{
			g_z[i] = ' ';
			while (g_z[i] == ' ')
				++i;
			g_z[--i] = '+';
		}
	}
	else
	{
		if (g_z[i] == '-')
		{
			g_z[i] = ' ';
			while (g_z[i] == ' ')
				++i;
			g_z[--i] = '-';
		}
	}
}

static void	ft_patch_help_pn(void)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (g_z[i] == '0' || g_z[i] == '+' || g_z[i] == ' ' || g_z[i] == '-')
	{
		if (g_z[i] == '0')
		{
			g_z[i] = ' ';
			++s;
		}
		++i;
	}
	while (--i > 0 && --s >= 0)
	{
		g_z[i] = '0';
	}
}

static void	ft_patch_pn(void)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (g_z[i])
	{
		if (g_z[i] == ' ')
			++s;
		++i;
	}
	if (s)
	{
		ft_patch_help_pn();
		if (g_mask & MASK_POINT && !(g_mask & MASK_NEG)
				&& g_mask & MASK_POS && ft_atoi(g_str) >= 0)
			ft_patch_to_patch(1);
		if (g_mask & MASK_POINT && !(g_mask & MASK_NEG)
				&& ft_atoi(g_str) < 0)
			ft_patch_to_patch(0);
	}
}

void		ft_patch(void)
{
	if ((g_mask & MASK_POINT || g_mask & MASK_ZERO)
			&& !(g_mask & MASK_U) && ft_atoi(g_str) < 0)
		ft_patch_pz();
	if (g_mask & MASK_POINT && !(g_mask & MASK_NEG) && ((g_mask & MASK_D)
				|| g_mask & MASK_O || g_mask & MASK_OO ||
				g_mask & MASK_X || g_mask & MASK_XX || g_mask & MASK_U
				|| g_mask & MASK_UU || g_mask & MASK_I))
		ft_patch_pn();
}
