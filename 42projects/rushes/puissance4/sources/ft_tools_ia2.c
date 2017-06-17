/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_ia2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 02:10:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/28 08:01:29 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance4.h"

int		ft_max(char **tab, int profondeur)
{
	int		max;
	int		i;
	int		j;
	int		tmp;

	if (!profondeur || ft_winner(tab))
		return (ft_eval(tab));
	max = -1000000;
	i = g_h;
	while (--i >= 0 && (j = -1))
	{
		while (++j < g_le)
		{
			if (tab[i][j] == 46 && (!tab[i + 1] || tab[i + 1][j] != 46))
			{
				tab[i][j] = 88;
				tmp = ft_min(tab, profondeur - 1);
				if (tmp > max || ((tmp == max) && (rand() % 2)))
					max = tmp;
				tab[i][j] = 46;
			}
		}
	}
	return (max);
}

int		ft_min(char **tab, int profondeur)
{
	int		min;
	int		i;
	int		j;
	int		tmp;

	if (!profondeur || ft_winner(tab))
		return (ft_eval(tab));
	min = 1000000;
	i = g_h;
	while (--i >= 0 && (j = -1))
	{
		while (++j < g_le)
		{
			if (tab[i][j] == 46 && (!tab[i + 1] || tab[i + 1][j] != 46))
			{
				tab[i][j] = 79;
				tmp = ft_max(tab, profondeur - 1);
				if (tmp < min || ((tmp == min) && (rand() % 2)))
					min = tmp;
				tab[i][j] = 46;
			}
		}
	}
	return (min);
}

void	ft_nb_series3(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	*sj1 = 0;
	*sj2 = 0;
	ft_checkdiagdown3(tab, sj1, sj2);
	ft_checkdiagup3(tab, sj1, sj2);
	ft_checklineh3(tab, sj1, sj2);
	ft_checklinev3(tab, sj1, sj2);
}

void	ft_nb_series4(char **tab, int *sj1, int *sj2)
{
	int		i;
	int		j;

	*sj1 = 0;
	*sj2 = 0;
	ft_checkdiagdown4(tab, sj1, sj2);
	ft_checkdiagup4(tab, sj1, sj2);
	ft_checklineh4(tab, sj1, sj2);
	ft_checklinev4(tab, sj1, sj2);
}

int		ft_winner(char **tab)
{
	int		i;
	int		j;
	int		j1;
	int		j2;

	ft_nb_series4(tab, &j1, &j2);
	if (j1)
		return (79);
	else if (j2)
		return (88);
	else
	{
		i = g_h;
		while (--i >= 0 && (j = -1))
		{
			while (++j < g_le)
			{
				if (tab[i][j] == 46)
					return (0);
			}
		}
	}
	return (3);
}
