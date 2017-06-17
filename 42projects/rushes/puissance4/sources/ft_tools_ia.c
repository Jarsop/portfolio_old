/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_ia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 22:18:44 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/28 08:06:07 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance4.h"

void	ft_checkdiagdown3(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 2)
	{
		j = g_le - 2;
		while (--j >= 0)
		{
			if (tab[i][j] == tab[i - 1][j - 1] &&
					tab[i][j] == tab[i - 2][j - 2])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}

void	ft_checkdiagup3(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 2)
	{
		j = -1;
		while (++j < g_le - 2)
		{
			if (tab[i][j] == tab[i - 1][j + 1] &&
					tab[i][j] == tab[i - 2][j + 2])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}

void	ft_checklineh3(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 0)
	{
		j = -1;
		while (++j < g_le - 2)
		{
			if (tab[i][j] == tab[i][j + 1] &&
					tab[i][j] == tab[i][j + 2])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}

void	ft_checklinev3(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	i = g_h;
	while (--i >= 2)
	{
		j = -1;
		while (++j < g_le)
		{
			if (tab[i][j] == tab[i - 1][j] &&
					tab[i][j] == tab[i - 2][j])
			{
				if (tab[i][j] == 79)
					++*sj1;
				else if (tab[i][j] == 88)
					++*sj2;
			}
		}
	}
}
