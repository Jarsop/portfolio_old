/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestresult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 03:40:11 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 19:13:31 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_bestfree(t_best *best)
{
	int		n;

	n = best->n;
	while (--n >= 0)
		ft_lstfree(best->lst[n]);
	free(best->lst);
	free(best);
}

t_best	*ft_initbest(t_best *best, int n, int i)
{
	int		d;
	t_best	*new;

	d = -1;
	if (!i)
	{
		if (!(best = (t_best*)ft_memalloc(sizeof(t_best))))
			return (NULL);
		if (!(best->lst = (t_list**)ft_memalloc(sizeof(t_list*) * n)))
			return (NULL);
		best->n = 1;
		return (best);
	}
	else
	{
		if (!(new = (t_best*)ft_memalloc(sizeof(t_best))))
			return (NULL);
		if (!(new->lst = (t_list**)ft_memalloc(sizeof(t_list*) * n)))
			return (NULL);
		new->n = n;
		while (++d < n - 1)
			new->lst[d] = ft_lstdup(&(best->lst[d]));
		ft_bestfree(best);
		return (new);
	}
}

int		ft_findbroad(t_hex *h, t_list **res, t_best *best, int nb)
{
	int		node;
	int		ret;

	node = 0;
	if (!ft_bestok(best))
		return (0);
	if (h->se == 2)
		return (1);
	while (node < h->n)
	{
		if (h->next[node])
		{
			if (ft_bnotinlist(h->next[node]->name, res) && nb <= h->nbhex)
			{
				ft_lstpushback(res, h->next[node]->name,
					ft_strlen(h->next[node]->name) + 1);
				if ((ret = ft_findbroad(h->next[node], res, best, nb + 1)))
					return (ret);
				ft_lstclrlast(res);
			}
		}
		++node;
	}
	return (0);
}

t_best	*ft_resolveb(t_best *best, t_hex *hex, t_list **res)
{
	int		r;

	r = 2;
	while (r)
	{
		r = ft_findbroad(hex, &(best->lst[best->n - 1]), best, 1);
		if (r == 1)
		{
			best = ft_initbest(best, best->n + 1, 1);
			best->lst[best->n - 1] = ft_lstdup(res);
		}
	}
	return (best);
}

t_list	*ft_findbest(t_list **res, t_hex *hex)
{
	t_best	*best;
	t_list	*done;
	t_list	*b;
	int		i;
	int		c;

	i = -1;
	b = NULL;
	best = NULL;
	best = ft_initbest(best, 1, 0);
	best->lst[0] = ft_lstdup(res);
	best = ft_resolveb(best, hex, res);
	c = ft_lstsize(&(best->lst[0]));
	while (++i < best->n - 1)
	{
		if (best->lst[i] && ft_lstsize(&(best->lst[i])) < c)
		{
			c = ft_lstsize(&(best->lst[i]));
			b = best->lst[i];
		}
	}
	b ? ft_lstfree(*res) : 0;
	done = b ? ft_lstdup(&b) : ft_lstdup(&best->lst[0]);
	ft_bestfree(best);
	return (done);
}
