/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:04:30 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 19:11:39 by jgeslin          ###   ########.fr       */
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

int		ft_bestok(t_best *best)
{
	int		i;

	i = -1;
	if (best->n > 1)
	{
		while (++i < best->n - 2 || !i)
		{
			if (ft_lstsize(&(best->lst[best->n - 1])) >=
			ft_lstsize(&(best->lst[i])))
				return (0);
		}
	}
	return (1);
}

int		ft_bnotinlist(char *name, t_list **res)
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
	ft_lstpushback(&res, h->name, ft_strlen(h->name) + 1);
	res = ft_findbest(&res, h);
	if (ft_lstsize(&res) > 1)
		ft_printresult(&res, hex, ants);
	else
		ft_error("ERROR\n");
	ft_lstfree(res);
}
