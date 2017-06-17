/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_job.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 16:57:13 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:19:26 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_opendircur(char *name)
{
	DIR			*dir;
	t_dirent	*d;
	t_ls		*ls;
	char		*path;

	ls = NULL;
	g_t = 0;
	if ((dir = opendir(name)))
	{
		while ((d = readdir(dir)))
		{
			path = ft_strjoin(name, "/");
			path = ft_strwjoin(path, d->d_name, 0);
			ft_helpopen(&ls, path, d->d_name);
			free(path);
			path = NULL;
		}
		ft_recupdata(&ls);
		ft_puts(&ls);
		ft_lsfree(ls);
		closedir(dir);
	}
}

static void	ft_helpjob(t_ls *t, int ac)
{
	while (t)
	{
		if (ac != 1 && t->err != ENOENT && t->right[0] == 'd')
			ft_printf("\n%s :\n", t->name);
		if (t->err == EACCES)
			ft_fprintf(2, "ft_ls: %s: %s\n", t->realname, t->serrno);
		if (t->err != ENOENT && t->right[0] == 'd')
			ft_opendircur(t->name);
		t = t->next;
	}
}

void		ft_job(char **av, int ac, t_f *f)
{
	t_ls	*ls;
	t_ls	*t;
	t_size	s;

	ls = NULL;
	ft_recuparg(&ls, ac, av);
	ft_recupdata(&ls);
	s = ft_size(&ls);
	t = ls;
	while (t)
	{
		if (!(g_m & LS_L) && t->err != ENOENT && t->right[0] != 'd')
			ft_printf("%s\n\n", t->name);
		else if (g_m & LS_L && t->err != ENOENT && t->right[0] != 'd')
			ft_putl(t, s);
		t = t->next;
	}
	t = ls;
	ft_helpjob(t, ac);
	ft_lsfree(ls);
}
