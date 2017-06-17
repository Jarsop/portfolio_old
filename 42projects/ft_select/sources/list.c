/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:50:15 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:32:17 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_ls	*ft_lsnew(char const *str)
{
	t_ls	*new;

	if (!(new = (t_ls*)ft_memalloc(sizeof(t_ls))))
		return (NULL);
	new->next = new;
	new->prev = new;
	new->opt = 0;
	if (!str)
	{
		new->str = NULL;
		new->len = 0;
		return (new);
	}
	else
	{
		if (!(new->str = ft_strdup(str)))
			return (NULL);
		new->len = ft_strlen(str);
	}
	return (new);
}

void		ft_lspushend(t_ls **alst, char const *str)
{
	t_ls *elem_tmp;
	t_ls *new;

	new = ft_lsnew(str);
	elem_tmp = *alst;
	if (elem_tmp)
	{
		while (elem_tmp->next != *alst)
			elem_tmp = elem_tmp->next;
		elem_tmp->next = new;
		new->prev = elem_tmp;
		new->next = *alst;
		elem_tmp = *alst;
		elem_tmp->prev = new;
	}
	else
	{
		*alst = new;
		new->opt |= CURSOR;
	}
}

int			ft_lssize(t_ls **ls)
{
	t_ls	*tmp;
	int		len;

	len = 0;
	tmp = *ls;
	if (tmp)
	{
		while (tmp->next != *ls)
		{
			++len;
			tmp = tmp->next;
		}
		++len;
	}
	return (len);
}

int			ft_lslenmax(t_ls **ls)
{
	t_ls	*tmp;
	int		lenmax;

	lenmax = 0;
	tmp = *ls;
	while (tmp->next != *ls)
	{
		if (tmp->len > lenmax)
			lenmax = tmp->len;
		tmp = tmp->next;
	}
	if (tmp->len > lenmax)
		lenmax = tmp->len;
	return (lenmax);
}

int			ft_delselect(t_ls **ls)
{
	t_ls	*tmpn;
	int		size;
	int		i;

	i = -1;
	size = ft_lssize(ls);
	tmpn = *ls;
	if (size == 1)
		return (1);
	while (++i != size)
	{
		if (tmpn->opt & CURSOR)
		{
			tmpn->prev->next = tmpn->next;
			tmpn->next->prev = tmpn->prev;
			tmpn->next->opt |= CURSOR;
			if (!i)
				*ls = tmpn->next;
			ft_lsfreeone(tmpn);
			return (0);
		}
		tmpn = tmpn->next;
	}
	return (-1);
}
