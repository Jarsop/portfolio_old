/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playerturn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:07:37 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/28 02:08:04 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include <stdio.h>

int		ft_askcolumn(int fd)
{
	int		ret;
	char	*line;
	int		pcolumn;

	pcolumn = 0;
	while (pcolumn > g_h + 1 || !pcolumn)
	{
		ft_putstr("which column do you want to play ? (1 to lenght)\n");
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (-1);
		pcolumn = ft_atoi(line);
		if (pcolumn > g_le + 1 || !pcolumn)
			ft_putstr("ERROR, lenght must be between 1 and lenght\n");
	}
	return (pcolumn);
}

int		ft_columnlen(char **tab, int pcolumn)
{
	int a;

	a = 0;
	while (a < g_h)
	{
		if (tab[a][pcolumn] != 46 && a != 0)
			return (a);
		if (tab[a][pcolumn] != 46 && a == 0)
		{
			ft_putstr("ERROR, you can not place it here\n");
			ft_filltab(tab);
		}
		a++;
	}
	return (a);
}

char	**ft_filltab(char **tab)
{
	int		c;
	int		pcolumn;

	pcolumn = ft_askcolumn(0) - 1;
	c = ft_columnlen(tab, pcolumn) - 1;
	tab[c][pcolumn] = 'X';
	return (tab);
}
