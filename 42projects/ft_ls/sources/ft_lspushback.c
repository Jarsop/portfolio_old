/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lspushback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:49:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/24 20:16:18 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lstrit(t_ls **alst, char const *name, char *realname)
{
	t_ls	*tmp1;
	t_ls	*tmp2;
	t_ls	*new;

	tmp1 = *alst;
	tmp2 = NULL;
	new = ft_lsnew(name, realname);
	lstat(new->name, new->stat);
	new->mt = new->stat->st_mtimespec.tv_sec;
	if (tmp1)
	{
		while (tmp1 && (tmp1->mt > new->mt || (tmp1->mt == new->mt &&
						ft_strcmp(tmp1->name, new->name) < 0)))
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		new->next = tmp1;
		if (!tmp2)
			*alst = new;
		else
			tmp2->next = new;
	}
	else
		*alst = new;
}

void	ft_lstritr(t_ls **alst, char const *name, char *realname)
{
	t_ls	*tmp1;
	t_ls	*tmp2;
	t_ls	*new;

	tmp1 = *alst;
	tmp2 = NULL;
	new = ft_lsnew(name, realname);
	lstat(new->name, new->stat);
	new->mt = new->stat->st_mtimespec.tv_sec;
	if (tmp1)
	{
		while (tmp1 && tmp1->mt < new->mt)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		new->next = tmp1;
		if (!tmp2)
			*alst = new;
		else
			tmp2->next = new;
	}
	else
		*alst = new;
}

void	ft_lspush(t_ls **alst, char const *name, char *realname)
{
	t_ls	*tmp1;
	t_ls	*new;

	tmp1 = *alst;
	new = ft_lsnew(name, realname);
	if (tmp1)
	{
		while (tmp1->next)
			tmp1 = tmp1->next;
		tmp1->next = new;
	}
	else
		*alst = new;
}

void	ft_lspushback(t_ls **alst, char const *name, char *realname)
{
	t_ls	*tmp1;
	t_ls	*tmp2;
	t_ls	*new;

	tmp1 = *alst;
	tmp2 = NULL;
	new = ft_lsnew(name, realname);
	if (tmp1)
	{
		while (tmp1 && ft_strcmp(tmp1->name, new->name) < 0)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		new->next = tmp1;
		if (!tmp2)
			*alst = new;
		else
			tmp2->next = new;
	}
	else
		*alst = new;
}

void	ft_lspushbackr(t_ls **alst, char const *name, char *realname)
{
	t_ls	*tmp1;
	t_ls	*tmp2;
	t_ls	*new;

	tmp1 = *alst;
	tmp2 = NULL;
	new = ft_lsnew(name, realname);
	if (tmp1)
	{
		while (tmp1 && ft_strcmp(tmp1->name, new->name) > 0)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		new->next = tmp1;
		if (!tmp2)
			*alst = new;
		else
			tmp2->next = new;
	}
	else
		*alst = new;
}
