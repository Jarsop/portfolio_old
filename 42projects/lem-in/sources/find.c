/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:04:30 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/22 03:26:47 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_antsnb(t_list **rec)
{
	t_list	*t;

	t = *rec;
	while (t)
	{
		if (ft_strdigit(t->content))
			return (ft_atol_base(t->content, "0123456789"));
		t = t->next;
	}
	return (0);
}

int		ft_ants(t_list **rec)
{
	int		ants;

	if ((ants = ft_antsnb(rec)) <= 0)
	{
		ft_error("ERROR\n");
		exit(1);
	}
	return (ants);
}

int		ft_notinlist(char *name, t_list **res)
{
	t_list	*t;

	t = *res;
	while (t)
	{
		if (!ft_strcmp(name, t->content))
			return (0);
		t = t->next;
	}
	return (1);
}

int		ft_findroad(t_hex *h, t_list **res, int nb)
{
	int		node;
	int		ret;

	node = 0;
	if (h->se == 2)
		return (1);
	while (node < h->n)
	{
		if (h->next[node])
		{
			if (ft_notinlist(h->next[node]->name, res) && nb <= h->nbhex)
			{
				ft_lstpushback(res, h->next[node]->name,
					ft_strlen(h->next[node]->name));
				if ((ret = ft_findroad(h->next[node], res, nb + 1)))
					return (ret);
				ft_lstclrlast(res);
			}
		}
		++node;
	}
	return (0);
}

void	ft_resolve(t_hex **hex, int ants)
{
	t_hex	*h;
	t_list	*res;
	int		node;

	h = *hex;
	res = NULL;
	node = -1;
	while (h->se != 1)
		h = h->prev;
	ft_lstpushback(&res, h->name, ft_strlen(h->name));
	while (node < 0)
		node = ft_findroad(h, &res, 1);
	if (node > 0)
		ft_printresult(&res, hex, ants);
	else
		ft_error("ERROR\n");
	ft_lstfree(res);
}
