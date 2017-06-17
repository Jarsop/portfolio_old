/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:52:28 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:28:00 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	ft_putspace(int len, int fd)
{
	char	str[len + 1];

	str[len] = 0;
	ft_memset(str, 32, len);
	ft_putstr_fd(str, fd);
}

void		ft_lsfreeone(t_ls *ls)
{
	free(ls->str);
	ls->next = NULL;
	ls->prev = NULL;
	free(ls);
}

void		ft_helpput(t_env *env, t_ls *tmp, int *job)
{
	env->lenjob += env->lenmax + 1;
	*job += env->lenmax + 1;
	if ((tmp->opt & CURSSEL) == CURSSEL)
		ft_curssel(tmp->str, 0);
	else if ((tmp->opt & CURSOR) == CURSOR)
		ft_cursor(tmp->str, 0);
	else if ((tmp->opt & SELECT) == SELECT)
		ft_select(tmp->str, 0);
	else
		ft_putstr_fd(tmp->str, 0);
	if (tmp->len != env->lenmax)
		ft_putspace(env->lenmax - tmp->len, 0);
	if (*job + env->lenmax + 1 > env->col)
	{
		ft_putchar_fd('\n', 0);
		*job = 0;
	}
	else
		ft_putchar_fd(' ', 0);
}

static void	ft_line_col(t_env *env)
{
	if (env->line > 5 && env->col > 14)
	{
		ft_putstr_fd("*.* Too Small!", 0);
		env->lenjob = 14;
		env->hjob = 0;
	}
	else
	{
		env->lenjob = 0;
		env->hjob = 0;
	}
}

int			ft_lenmax(t_env *env, int *len, int *cnt)
{
	*len += env->lenmax + 1;
	if (*len + env->lenmax + 1 > env->col)
	{
		if (*cnt > env->nbwl)
			env->nbwl = *cnt;
		*cnt = 0;
		*len = 0;
		if (++env->hjob + 3 > env->line)
		{
			ft_line_col(env);
			return (-1);
		}
	}
	return (0);
}
