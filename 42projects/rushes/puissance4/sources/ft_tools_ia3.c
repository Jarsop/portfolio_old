/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_ia3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 08:04:34 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/28 08:06:10 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance4.h"

void	ft_checkdiagdown4(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 3)
	{
		j = g_le - 3;
		while (--j >= 0)
		{
			if (tab[i][j] == tab[i - 1][j - 1] &&
					tab[i][j] == tab[i - 2][j - 2] &&
					tab[i][j] == tab[i - 3][j - 3])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}

void	ft_checkdiagup4(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 3)
	{
		j = -1;
		while (++j < g_le - 3)
		{
			if (tab[i][j] == tab[i - 1][j + 1] &&
					tab[i][j] == tab[i - 2][j + 2] &&
					tab[i][j] == tab[i - 3][j + 3])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}

void	ft_checklineh4(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 0)
	{
		j = -1;
		while (++j < g_le - 3)
		{
			if (tab[i][j] == tab[i][j + 1] &&
					tab[i][j] == tab[i][j + 2] &&
					tab[i][j] == tab[i][j + 3])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}

void	ft_checklinev4(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 3)
	{
		j = -1;
		while (++j < g_le)
		{
			if (tab[i][j] == tab[i - 1][j] &&
					tab[i][j] == tab[i - 2][j] &&
					tab[i][j] == tab[i - 3][j])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}
