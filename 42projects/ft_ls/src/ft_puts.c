/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:34:07 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:22:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_perm(t_ls *ls)
{
	char	*tmp;

	if (ls->err == EACCES && ft_strcmp(ls->realname, ".")
			&& ft_strcmp(ls->realname, ".."))
	{
		if (!g_perm[0])
			g_perm = ft_strwjoin("\n", g_perm, 1);
		g_perm = ft_strwjoin(g_perm, "\n", 0);
		g_perm = ft_strwjoin(g_perm, ls->name, 0);
		g_perm = ft_strwjoin(g_perm, ":\n", 0);
		tmp = ft_strjoin("ft_ls: ", ls->realname);
		tmp = ft_strwjoin(tmp, ": ", 0);
		tmp = ft_strwjoin(tmp, ls->serrno, 0);
		tmp = ft_strwjoin(tmp, "\n", 0);
		g_perm = ft_strwjoin(g_perm, tmp, 2);
	}
}

static void	ft_putlsl1(t_ls *t, t_size s, int tmp)
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

static void	ft_putlsl2(t_ls *t, t_size s, int tmp)
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
		(tmp = ft_sizen(t->stat->st_size)) <= s.block ? ft_psp(s.block - tmp)
			: ft_putchar(' ');
		ft_printf(" %d ", t->stat->st_size);
	}
	ft_putcolor(t, NULL, 2);
}

void		ft_putlsl(t_ls **ls)
{
	t_ls	*t;
	t_size	s;
	int		tmp;

	t = *ls;
	s = ft_size(ls);
	g_perm = ft_strdup("\0");
	if (t->next->next)
		g_m & LS_RR ? ft_printf("\ntotal %d\n", g_t)
			: ft_printf("total %d\n", g_t);
	while (t)
	{
		if ((!(g_m & LS_A) && (t->realname[0] != '.' || t->realname[1] == '/'))
				|| g_m & LS_A || g_m & LS_F)
		{
			if (g_m & LS_RR)
				ft_perm(t);
			ft_printf("%s ", t->right);
			ft_putlsl1(t, s, tmp);
			ft_putlsl2(t, s, tmp);
		}
		t = t->next;
	}
	ft_error(g_perm);
	free(g_perm);
}
