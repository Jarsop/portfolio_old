/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:27:08 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:40:33 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_recursivels(t_ls **ls)
{
	t_ls	*t;
	DIR		*d;
	int		i;

	t = *ls;
	while (t)
	{
		i = 0;
		if (ft_strcmp(t->realname, ".") && ft_strcmp(t->realname, "..") &&
			((!(g_m & LS_A) && (t->realname[0] != '.' || t->realname[1] == '/'))
			|| g_m & LS_A || g_m & LS_F) && t->stat->st_mode & S_IFDIR &&
			(d = opendir(t->name)) && ++i)
		{
			if (!errno || t->err != EACCES)
			{
				ft_printf("\n%s:", t->name);
				ft_opendircur(t->name);
			}
			errno = 0;
		}
		if (i)
			closedir(d);
		t = t->next;
	}
}

void		ft_helpopen(t_ls **ls, char *path, char *name)
{
	if (g_m & LS_F)
		ft_lspush(ls, path, name);
	else if (g_m & LS_R && !(g_m & LS_T))
		ft_lspushbackr(ls, path, name);
	else if (g_m & LS_T)
		g_m & LS_R ? ft_lstritr(ls, path, name) :
			ft_lstrit(ls, path, name);
	else
		ft_lspushback(ls, path, name);
}

void		ft_puts(t_ls **ls)
{
	if (g_m & LS_L)
		ft_putlsl(ls);
	else
		ft_putls(ls);
	if (g_m & LS_RR)
		ft_recursivels(ls);
}

void		ft_help3(t_ls *t, char *c, int m)
{
	if (t->right[9] == 't' || t->right[9] == 'T')
		ft_printf("%s \033[30;42m%s\033[0m%s\n", t->mtime, t->realname,
			m ? c : "\0");
	else
		ft_printf("%s \033[30;43m%s\033[0m%s\n", t->mtime, t->realname, m
					? c : "\0");
}

void		ft_help1(t_ls *t, char *p, char *c, int m)
{
	if (t->right[9] == 't' || t->right[9] == 'T')
		ft_printf("\n\033[30;42m%s\033[0m%s%s",
			t->realname, m ? c : "\0", p);
	else
		ft_printf("\n\033[30;43m%s\033[0m%s%s",
			t->realname, m ? c : "\0", p);
}
