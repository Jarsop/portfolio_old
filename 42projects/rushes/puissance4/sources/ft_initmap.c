/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:24:25 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/28 06:42:24 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

char	**ft_initmap(void)
{
	int		a;
	char	**tab;

	a = -1;
	tab = (char**)malloc(sizeof(char*) * (g_h + 1));
	while (++a < g_h)
		tab[a] = ft_memset(ft_strnew(g_le), 46, g_le);
	return (tab);
}

void	ft_printtab(char **tab)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i])
	{
		ft_putchar('|');
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 88)
				ft_putwchar(128308);
			else if (tab[i][j] == 79)
				ft_putwchar(128309);
			else
				ft_putchar(tab[i][j]);
			ft_putstr(" |");
		}
		ft_putchar('\n');
	}
	ft_putchar('\n');
}
