/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:30:08 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/28 04:07:04 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"
#include "../libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int		ft_getlenght(int fd)
{
	int		ret;
	char	*line;

	g_le = 0;
	while (g_le < 7 || g_le > 1000)
	{
		ft_putstr("Define lenght between 7 and 1000\n");
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		g_le = ft_atoi(line);
		if (g_le < 7 || g_le > 1000)
			ft_putstr("ERROR, lenght must be >= 7 and < 1000\n");
	}
	return (g_le);
}

int		ft_getheight(int fd)
{
	int		ret;
	char	*line;

	g_h = 0;
	while (g_h < 6 || g_h > 1000)
	{
		ft_putstr("Define height between 6 and 1000\n");
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (1);
		g_h = ft_atoi(line);
		if (g_h < 6 || g_h > 1000)
			ft_putstr("ERROR, height must be >= 6 and < 1000\n");
	}
	return (g_h);
}

int		ft_fulltab(char **tab)
{
	int		a;
	int		b;

	a = -1;
	b = -1;
	while (++a < g_h)
	{
		while (++b < g_le)
		{
			if (!ft_isalpha(tab[a][b]))
				return (0);
		}
	}
	return (1);
}

int		read_file(int fd, int rand)
{
	char	**tab;
	int		a;

	g_le = ft_getlenght(fd);
	g_h = ft_getheight(fd);
	tab = ft_initmap();
	!rand ? ft_putendl("You begin !") : ft_putendl("IA begin");
	if (!rand)
		ft_printtab(tab);
	while (ft_win(tab))
	{
		if (!rand && ++rand)
			ft_printtab(ft_filltab(tab));
		else if (rand && !(rand = 0))
		{
			ft_iaturn(tab, 5);
			ft_printtab(tab);
		}
		if (ft_fulltab(tab))
			ft_putstr("END OF GAME WITH NULL SCORE\n");
	}
	free(tab);
	return (0);
}

int		main(void)
{
	srand(time(NULL));
	if (read_file(0, (rand() % 2)))
		ft_putstr("ERROR\n");
	return (0);
}
