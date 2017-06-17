/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:42:09 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/24 23:03:14 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_inittab(t_f *f)
{
	f[0].f = 'l';
	f[0].m = LS_L;
	f[1].f = 'R';
	f[1].m = LS_RR;
	f[2].f = 'a';
	f[2].m = LS_A;
	f[3].f = 'r';
	f[3].m = LS_R;
	f[4].f = 't';
	f[4].m = LS_T;
	f[5].f = 'G';
	f[5].m = LS_GG;
	f[6].f = 'f';
	f[6].m = LS_F;
	f[7].f = '1';
	f[7].m = LS_UN;
	f[8].f = 'F';
	f[8].m = LS_FF;
}

int			main(int ac, char **av)
{
	t_f		f[LS_TAB];

	g_m = 0;
	ft_inittab(f);
	ft_lsstart(ac, av, f);
	return (0);
}
