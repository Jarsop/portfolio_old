/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 19:11:36 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:19:30 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_select_r(t_ls **ls)
{
	t_ls	*tmp;
	int		size;
	int		i;

	tmp = *ls;
	i = -1;
	size = ft_lssize(ls);
	while (++i != size)
	{
		if (tmp->opt & CURSOR)
		{
			tmp->opt ^= CURSOR;
			tmp = tmp->next;
			tmp->opt |= CURSOR;
		}
		tmp = tmp->next;
	}
}

void	ft_select_l(t_ls **ls)
{
	t_ls	*tmp;
	int		size;
	int		i;

	tmp = *ls;
	i = -1;
	size = ft_lssize(ls);
	while (++i != size)
	{
		if (tmp->opt & CURSOR)
		{
			tmp->opt ^= CURSOR;
			tmp = tmp->prev;
			tmp->opt |= CURSOR;
		}
		tmp = tmp->prev;
	}
}

void	ft_select_s(t_ls **ls)
{
	t_ls	*tmp;
	int		size;
	int		i;

	i = -1;
	size = ft_lssize(ls);
	tmp = *ls;
	while (++i != size)
	{
		if (tmp->opt & CURSOR)
		{
			if (tmp->opt & SELECT)
				tmp->opt ^= SELECT;
			else
				tmp->opt |= SELECT;
		}
		tmp = tmp->next;
	}
	ft_select_r(ls);
}

void	ft_select_up(t_ls **ls, t_env *env)
{
	t_ls	*tmp;
	int		i;
	int		nb[3];

	i = -1;
	nb[0] = 0;
	nb[1] = 0;
	tmp = *ls;
	while (++i != ft_lssize(ls))
	{
		if (nb[0] == env->nbwl && ++nb[1])
			nb[0] = 0;
		if (tmp->opt & CURSOR)
		{
			tmp->opt ^= CURSOR;
			nb[2] = i - env->nbwl;
			while (i-- != nb[2])
				tmp = tmp->prev;
			tmp->opt |= CURSOR;
			break ;
		}
		tmp = tmp->next;
		++nb[0];
	}
}

void	ft_select_down(t_ls **ls, t_env *env)
{
	t_ls	*tmp;
	int		i;
	int		nb[3];

	i = -1;
	nb[0] = 0;
	nb[1] = 0;
	tmp = *ls;
	while (++i != ft_lssize(ls))
	{
		if (nb[0] == env->nbwl && ++nb[1])
			nb[0] = 0;
		if (tmp->opt & CURSOR)
		{
			tmp->opt ^= CURSOR;
			nb[2] = i + env->nbwl;
			while (i++ != nb[2])
				tmp = tmp->next;
			tmp->opt |= CURSOR;
			break ;
		}
		tmp = tmp->next;
		++nb[0];
	}
}
