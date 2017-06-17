/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:48:13 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:16:30 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_putl1(t_ls *t, t_size s, int tmp)
{
	(tmp = ft_sizen(t->stat->st_nlink)) <= s.nlink ? ft_psp(s.nlink - tmp)
		: ft_putstr("  ");
	if (t->pname)
	{
		ft_printf("%d %s ", t->stat->st_nlink, t->pname);
		(tmp = ft_strlen(t->pname)) <= s.usr ? ft_psp(s.usr - tmp + 1)
			: ft_putchar(' ');
	}
	else
	{
		ft_printf("1000");
		4 <= s.grp ? ft_psp(s.grp - 4 + 1) : ft_putchar(' ');
	}
	if (t->gname)
	{
		ft_printf("%s", t->gname);
		(tmp = ft_strlen(t->gname)) <= s.grp ? ft_psp(s.grp - tmp + 1)
			: ft_putchar(' ');
	}
	else
	{
		ft_printf("101");
		3 <= s.grp ? ft_psp(s.grp - 3 + 1) : ft_putchar(' ');
	}
}

static void	ft_putl2(t_ls *t, t_size s, int tmp)
{
	if (t->right[0] == 'c' || t->right[0] == 'b')
	{
		(tmp = ft_sizen(t->major)) <= s.maj ? ft_psp(s.maj - tmp)
			: ft_putchar(' ');
		ft_printf("%d, ", t->major);
		(tmp = ft_sizen(t->minor)) <= s.min ? ft_psp(s.min - tmp)
			: ft_putchar(' ');
		ft_printf("%d ", t->minor);
	}
	else
	{
		(tmp = ft_sizen(t->stat->st_size)) <= s.block ?
			ft_psp(s.block - tmp) : ft_putchar(' ');
		ft_printf(" %d ", t->stat->st_size);
	}
}

void		ft_putl(t_ls *t, t_size s)
{
	int		tmp;

	if ((!(g_m & LS_A) && (t->realname[0] != '.' || t->realname[1] == '/'))
			|| g_m & LS_A || g_m & LS_F)
	{
		if (g_m & LS_RR)
			ft_perm(t);
		ft_printf("%s", t->right);
		ft_putl1(t, s, tmp);
		ft_putl2(t, s, tmp);
		ft_putcolor(t, NULL, 2);
	}
}
