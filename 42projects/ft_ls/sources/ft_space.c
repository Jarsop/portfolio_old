/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:39:47 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:14:43 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_init_size(t_size *s)
{
	s->nlink = 0;
	s->usr = 0;
	s->grp = 0;
	s->block = 0;
	s->min = 0;
	s->maj = 0;
	s->time = 0;
	s->path = 0;
}

int			ft_sizen(int nb)
{
	int		i;

	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		++i;
	}
	return (i);
}

static void	ft_helpsize(t_size *s, t_ls *t)
{
	if (ft_sizen(t->major) > s->maj)
		s->maj = ft_sizen(t->major);
	if (ft_sizen(t->minor) > s->min)
		s->min = ft_sizen(t->minor);
	if (s->min + s->maj + 1 > s->block)
		s->block = s->min + s->maj + 1;
}

t_size		ft_size(t_ls **ls)
{
	t_size	s;
	t_ls	*t;

	t = *ls;
	ft_init_size(&s);
	while (t)
	{
		if (t->stat->st_nlink && ft_sizen(t->stat->st_nlink) > s.nlink)
			s.nlink = ft_sizen(t->stat->st_nlink);
		if (t->pname && ft_strlen(t->pname) > s.usr)
			s.usr = ft_strlen(t->pname);
		else if (!t->pname && 4 > s.usr)
			s.usr = 4;
		if (t->gname && ft_strlen(t->gname) > s.grp)
			s.grp = ft_strlen(t->gname);
		else if (!t->gname && 3 > s.grp)
			s.grp = 3;
		if (t->right && (t->right[0] == 'c' || t->right[0] == 'b'))
			ft_helpsize(&s, t);
		else if (t->stat->st_size && ft_sizen(t->stat->st_size) > s.block)
			s.block = ft_sizen(t->stat->st_size);
		t = t->next;
	}
	return (s);
}

void		ft_psp(int nb)
{
	while (nb--)
		ft_putchar(' ');
}
