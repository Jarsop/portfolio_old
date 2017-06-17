/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:35:59 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:23:08 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*ft_time(t_ls *ls)
{
	time_t	t;
	char	*tmp;
	char	*f;

	t = time(NULL);
	tmp = ctime((const time_t *)&(ls->stat->st_mtime));
	if (t - ls->stat->st_mtimespec.tv_sec > 15776999 ||
			t - ls->stat->st_mtimespec.tv_sec < 0)
	{
		f = ft_strdup(tmp);
		tmp = ft_strndup(&tmp[4], 6);
		tmp = ft_strwjoin(tmp, " ", 0);
		tmp = ft_strwjoin(tmp, &f[19], 0);
		tmp[ft_strlen(tmp) - 1] = 0;
		free(f);
	}
	else
		tmp = ft_strndup(&tmp[4], 12);
	return (tmp);
}

static void	ft_helprecup(t_ls *tmp)
{
	g_t += tmp->stat->st_blocks;
	if (!(g_m & LS_A) && tmp->realname[0] == '.')
		g_t -= tmp->stat->st_blocks;
	if (tmp->stat->st_mode & S_IFLNK)
		readlink(tmp->name, tmp->lnk, 1024);
	tmp->right = ft_right(tmp->stat->st_mode);
	if (tmp->right[0] == 'c')
	{
		tmp->minor = minor(tmp->stat->st_rdev);
		tmp->major = major(tmp->stat->st_rdev);
	}
}

void		ft_recupdata(t_ls **ls)
{
	t_ls	*tmp;
	DIR		*dir;

	tmp = *ls;
	while (tmp)
	{
		if ((dir = opendir(tmp->name)))
			closedir(dir);
		if (errno == ENOENT && ft_strcmp(tmp->realname, "."))
			ft_fprintf(2, "ft_ls : %s: %s\n", tmp->realname, strerror(errno));
		tmp->ret = lstat((tmp->name), tmp->stat);
		tmp->serrno = ft_strdup(strerror(errno));
		tmp->err = errno;
		errno = 0;
		ft_helprecup(tmp);
		tmp->mtime = ft_time(tmp);
		if ((tmp->group = getgrgid(tmp->stat->st_gid)))
			tmp->gname = ft_strdup(tmp->group->gr_name);
		if ((tmp->passwd = getpwuid(tmp->stat->st_uid)))
			tmp->pname = ft_strdup(tmp->passwd->pw_name);
		tmp = tmp->next;
	}
}

void		ft_recuparg(t_ls **ls, int ac, char **av)
{
	int		i;

	i = -1;
	while (++i < ac)
	{
		if (g_m & LS_F)
			ft_lspush(ls, av[i], av[i]);
		else if (g_m & LS_R)
			ft_lspushbackr(ls, av[i], av[i]);
		else if (g_m & LS_T)
			g_m & LS_R ? ft_lstritr(ls, av[i], av[i]) :
				ft_lstrit(ls, av[i], av[i]);
		else
			ft_lspushback(ls, av[i], av[i]);
	}
}
