/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsstart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:18:47 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/24 23:03:17 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_illegalflag(char *s, char av)
{
	s[0] = av;
	ft_error("ft_ls: illegal option -- ");
	ft_error(s);
	ft_error("\nusage: ft_ls [-FGR1aflrt] [file ...]\n");
	return (-1);
}

int		ft_getflag(char *av, t_f *f)
{
	int		i;
	char	s[2];

	s[1] = 0;
	if (*av == '-' && *(av + 1))
	{
		if (av[1] == '-' && av[2] != '\0')
			return (ft_illegalflag(&s[0], *av));
		while (*++av)
		{
			i = -1;
			while (++i < LS_TAB)
			{
				if (*av == f[i].f)
				{
					g_m |= f[i].m;
					break ;
				}
			}
			if (i == LS_TAB)
				return (ft_illegalflag(&s[0], *av));
		}
		return (1);
	}
	return (0);
}

void	ft_lsstart(int ac, char **av, t_f *f)
{
	t_ls	*ls;
	int		i;
	int		r;

	ls = NULL;
	i = 0;
	while (++i < ac)
	{
		if (!ft_strcmp("--", av[i]))
		{
			++i;
			if (ac > 2)
				ft_job(&av[i], (ac - i), f);
			break ;
		}
		else if ((r = ft_getflag(av[i], f)) < 0)
			exit(0);
		else if (!r)
		{
			ft_job(&av[i], (ac - i), f);
			break ;
		}
	}
	if (i == ac)
		ft_opendircur(".");
}
