/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:22:20 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 19:31:14 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_putcolor0(t_ls *t, char *p, char *c)
{
	int		m;

	m = g_m & LS_FF;
	if (g_m & LS_GG && t->right[0] == 'l')
		ft_printf("\033[35m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else if (g_m & LS_GG && t->right[0] == 'p')
		ft_printf("\033[33m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else if (g_m & LS_GG && t->right[0] == 'c')
		ft_printf("\033[34;43m%s\033[0m%s", t->realname, p);
	else if (g_m & LS_GG && t->right[0] == 'b')
		ft_printf("\033[34;46m%s\033[0m%s", t->realname, p);
	else if (g_m & LS_GG && t->right[0] != '-' && t->right[2] == 'w' &&
			t->right[5] == 'w' && t->right[8] == 'w')
		ft_help0(t, p, c, m);
	else if (g_m & LS_GG && t->right[0] == 'd')
		ft_printf("\033[36;1m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else if (g_m & LS_GG && (t->right[3] == 'x' || t->right[6] == 'x' ||
				t->right[9] == 'x'))
		ft_printf("\033[31m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else
		ft_printf("%s%s%s", t->realname, m ? c : "\0", p);
}

static void	ft_putcolor1(t_ls *t, char *p, char *c)
{
	int		m;

	m = g_m & LS_FF;
	if (g_m & LS_GG && t->right[0] == 'l')
		ft_printf("\n\033[35m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else if (g_m & LS_GG && t->right[0] == 'p')
		ft_printf("\n\033[33m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else if (g_m & LS_GG && t->right[0] == 'c')
		ft_printf("\n\033[34;43m%s\033[0m%s", t->realname, p);
	else if (g_m & LS_GG && t->right[0] == 'b')
		ft_printf("\n\033[34;46m%s\033[0m%s", t->realname, p);
	else if (g_m & LS_GG && t->right[0] != '-' && t->right[2] == 'w'
			&& t->right[5] == 'w' && t->right[8] == 'w')
		ft_help1(t, p, c, m);
	else if (g_m & LS_GG && t->right[0] == 'd')
		ft_printf("\n\033[36;1m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else if (g_m & LS_GG && (t->right[3] == 'x' || t->right[6] == 'x' ||
				t->right[9] == 'x'))
		ft_printf("\n\033[31m%s\033[0m%s%s", t->realname, m ? c : "\0", p);
	else
		ft_printf("\n%s%s%s", t->realname, m ? c : "\0", p);
}

static void	ft_help2(t_ls *t, char *c, int m)
{
	if (g_m & LS_GG && t->right[0] == 'd')
		ft_printf("%s \033[36;1m%s\033[0m%s\n", t->mtime, t->realname,
				m ? c : "\0");
	else if (g_m & LS_GG && (t->right[3] == 'x' || t->right[6] == 'x' ||
			t->right[9] == 'x'))
		ft_printf("%s \033[31m%s\033[0m%s\n", t->mtime, t->realname,
				m ? c : "\0");
	else
	{
		if (t->right[0] == 'l')
			ft_printf("%s %s%s -> %s\n", t->mtime, t->realname, m ? c : "\0",
					t->lnk);
		else
			ft_printf("%s %s%s\n", t->mtime, t->realname, m ? c : "\0");
	}
}

static void	ft_putcolor2(t_ls *t, char *c)
{
	int		m;

	m = g_m & LS_FF;
	if (g_m & LS_GG && t->right[0] == 'l')
		ft_printf("%s \033[35m%s\033[0m%s -> %s\n", t->mtime, t->realname,
				m ? c : "\0", t->lnk);
	else if (g_m & LS_GG && t->right[0] == 'p')
		ft_printf("%s \033[33m%s\033[0m%s\n", t->mtime, t->realname,
				m ? c : "\0");
	else if (g_m & LS_GG && t->right[0] == 'c')
		ft_printf("%s \033[34;43m%s\033[0m\n", t->mtime, t->realname);
	else if (g_m & LS_GG && t->right[0] == 'b')
		ft_printf("%s \033[34;46m%s\033[0m\n", t->mtime, t->realname);
	else if (g_m & LS_GG && t->right[0] != '-' && t->right[2] == 'w' &&
			t->right[5] == 'w' && t->right[8] == 'w')
		ft_help3(t, c, m);
	else
		ft_help2(t, c, m);
}

void		ft_putcolor(t_ls *t, char *p, int i)
{
	char	c;

	c = ft_def(t);
	if (!i)
		ft_putcolor0(t, p, &c);
	else if (i == 1)
		ft_putcolor1(t, p, &c);
	else if (i == 2)
		ft_putcolor2(t, &c);
}
