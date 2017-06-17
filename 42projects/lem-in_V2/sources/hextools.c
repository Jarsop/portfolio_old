/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 12:27:44 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/21 23:40:59 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_freehex(t_hex *hex)
{
	if (hex)
	{
		if (hex->prev)
			ft_freehex(hex->prev);
		if (hex->name)
			free(hex->name);
		if (hex->next)
			free(hex->next);
		free(hex);
	}
}

void	ft_nbrhex(t_hex **hex, t_list **rec)
{
	t_list	*t;
	t_hex	*h;
	char	*s;
	int		nb;

	t = *rec;
	h = *hex;
	nb = 0;
	while (t)
	{
		s = (char*)t->content;
		if (t->content_size && s[0] != 'L' && s[0] != '#')
			++nb;
		t = t->next;
	}
	while (h)
	{
		h->nbhex = nb;
		h = h->prev;
	}
}

t_hex	*ft_hexnew(char *str, int node)
{
	t_hex	*new;

	if (!(new = (t_hex*)ft_memalloc(sizeof(t_hex))))
		return (NULL);
	new->prev = NULL;
	new->n = node;
	if (!(new->next = (t_hex**)ft_memalloc(sizeof(t_hex*) * node)))
		return (NULL);
	while (--node > 0)
		new->next[node] = NULL;
	if (!str)
		return (NULL);
	else
	{
		if (!(new->name = ft_strdup(str)))
			return (NULL);
	}
	return (new);
}

void	ft_hexpushback(t_hex **hex, char *str, int node)
{
	t_hex	*tmp;
	t_hex	*new;
	int		p;

	tmp = *hex;
	if (!str)
		exit(1);
	new = ft_hexnew(str, node);
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		tmp->prev = new;
	}
	else
		*hex = new;
}
