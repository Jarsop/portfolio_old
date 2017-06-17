/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 18:07:43 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:21:44 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int	ft_be_space_or_not_be_space(t_ls *ls, t_ls *cur)
{
	if (cur != ls)
	{
		while (cur != ls)
		{
			if (cur->opt & SELECT)
				return (1);
			cur = cur->next;
		}
	}
	else if (cur == ls && cur->opt & SELECT)
		return (1);
	return (0);
}

void		ft_putselect(t_ls **ls, int fd)
{
	t_ls	*tmp;
	int		size;
	int		i;
	int		o;

	tmp = *ls;
	i = -1;
	size = ft_lssize(ls);
	while (++i != size)
	{
		o = 0;
		if (tmp->opt & SELECT && ++o)
			ft_putstr_fd(tmp->str, fd);
		tmp = tmp->next;
		if (o && ft_be_space_or_not_be_space(*ls, tmp))
			ft_putchar_fd(32, fd);
	}
}

static int	ft_checkjob(t_env *env, t_ls **ls)
{
	int		size;
	int		i;
	int		len;
	int		cnt;

	i = -1;
	len = 0;
	cnt = 1;
	env->nbwl = 0;
	env->hjob = 0;
	size = ft_lssize(ls);
	if (env->lenmax + 1 > env->col)
		return (-1);
	while (++i != size)
	{
		if (ft_lenmax(env, &len, &cnt) < 0)
			return (-1);
		++cnt;
	}
	env->nbwe = cnt;
	return (0);
}

void		ft_putjob(t_ls **ls, t_env *env)
{
	t_ls	*tmp;
	int		job;
	int		size;
	int		i;

	tmp = *ls;
	job = 0;
	i = -1;
	env->lenjob = 0;
	size = ft_lssize(ls);
	ft_putstr_fd("\033[0;32m", 0);
	if (!ft_checkjob(env, ls))
	{
		while (++i != size)
		{
			ft_helpput(env, tmp, &job);
			tmp = tmp->next;
		}
	}
	ft_putstr_fd("\033[00m", 0);
}

void		ft_clearjob(size_t *lenjob, size_t *hjob, int fd)
{
	if (!*hjob)
	{
		while (*lenjob)
		{
			--*lenjob;
			ft_caps("le", fd);
		}
		ft_caps("cd", fd);
	}
	else
	{
		while (*hjob)
		{
			ft_caps("cr", fd);
			ft_caps("up", fd);
			--*hjob;
		}
		ft_caps("cd", fd);
	}
}
