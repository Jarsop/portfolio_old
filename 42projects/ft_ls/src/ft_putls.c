/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:18:00 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:15:55 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	ft_sizewin(void)
{
	struct winsize	s_w;

	ioctl(0, TIOCGWINSZ, &s_w);
	return (s_w.ws_col);
}

static int	ft_resize(t_ls **ls)
{
	t_ls	*t;
	int		s;

	t = *ls;
	s = 0;
	while (t)
	{
		if (t->realname && ft_strlen(t->realname) > s)
			s = ft_strlen(t->realname);
		t = t->next;
	}
	return (g_m & LS_FF ? s + 2 : s + 1);
}

static char	*ft_printspace(int s, int smax)
{
	char	*sp;

	sp = ft_strnew(s - smax);
	ft_memset(sp, ' ', s - smax);
	return (sp);
}

static void	ft_padding(t_ls *t, int *tot)
{
	char	*p;

	if (g_m & LS_RR && t->err)
		if (t->err == EACCES)
			ft_perm(t);
	tot[1] = ft_strlen(t->realname);
	if (tot[0] + tot[1] + (tot[3] - tot[1]) < tot[2])
	{
		tot[0] += tot[1] + (tot[3] - tot[1]);
		ft_putcolor(t, (p = ft_printspace(tot[3], tot[1])), 0);
		free(p);
	}
	else
	{
		tot[0] = tot[1] + (tot[3] - tot[1]);
		ft_putcolor(t, (p = ft_printspace(tot[3], tot[1])), 1);
		free(p);
	}
}

void		ft_putls(t_ls **ls)
{
	t_ls	*t;
	int		tot[4];
	char	*p;

	t = *ls;
	tot[0] = 0;
	tot[1] = 0;
	g_perm = ft_strdup("\0");
	tot[2] = ft_sizewin();
	tot[3] = ft_resize(ls);
	!(g_m & LS_UN) && g_m & LS_RR ? ft_putchar('\n') : 0;
	while (t)
	{
		if (g_m & LS_UN && ((!(g_m & LS_A) && t->realname[0] != 46) ||
					g_m & LS_A || g_m & LS_F))
			ft_putcolor(t, "\0", 1);
		else if ((!(g_m & LS_A) && t->realname[0] != 46) ||
				g_m & LS_A || g_m & LS_F)
			ft_padding(t, tot);
		t = t->next;
	}
	if ((g_m & LS_RR))
		ft_error(g_perm);
	free(g_perm);
	ft_putchar('\n');
}
