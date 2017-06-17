/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iaturn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:50:38 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/28 08:01:50 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/puissance4.h"

static int	ft_helpia(int t, int i, int j)
{
	g_maxi = i;
	g_maxj = j;
	return (t);
}

static int	ft_helpeval(int winner, int nbp)
{
	if (winner == 79)
		return (1000000 - nbp);
	else if (winner == 88)
		return (-1000000 + nbp);
	else
		return (0);
}

void		ft_iaturn(char **tab, int profondeur)
{
	int		max;
	int		t;
	int		i;
	int		j;

	max = -1000000;
	i = g_h;
	while (--i >= 0 && (j = -1))
	{
		while (++j < g_le)
		{
			if (tab[i][j] == 46 && (!tab[i + 1] || tab[i + 1][j] != 46))
			{
				tab[i][j] = 79;
				t = ft_min(tab, profondeur - 1);
				if ((t > max || ((t == max) && (rand() % 2))))
					max = ft_helpia(t, i, j);
				tab[i][j] = 46;
			}
		}
	}
	tab[g_maxi][g_maxj] = 79;
}

int			ft_eval(char **tab)
{
	int		winner;
	int		nbp;
	int		i;
	int		j;

	nbp = 0;
	g_sj1 = 0;
	g_sj2 = 0;
	i = g_h;
	while (--i >= 0 && (j = g_le))
	{
		while (--j >= 0)
		{
			if (tab[i][j] != 46)
				nbp++;
		}
	}
	if ((winner = ft_winner(tab)))
		return (ft_helpeval(winner, nbp));
	ft_nb_series3(tab, &g_sj1, &g_sj2);
	return (g_sj1 - g_sj2);
}
