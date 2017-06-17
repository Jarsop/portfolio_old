/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 00:30:01 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/22 03:33:46 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_list	*ft_resetlst(t_list **res)
{
	t_list	*t;

	t = *res;
	while (t->next)
	{
		t->content_size = 0;
		t = t->next;
	}
	t->content_size = 0;
	return (t);
}

void	ft_findse(t_hex **hex, char **se)
{
	t_hex	*h;

	h = *hex;
	while (h)
	{
		if (h->se == 1)
			se[0] = h->name;
		if (h->se == 2)
			se[1] = h->name;
		h = h->prev;
	}
}

void	ft_jumplst(t_list **res)
{
	t_list	*jump;

	jump = *res;
	while (jump->prev)
	{
		if (jump)
			jump->content_size = jump->prev->content_size;
		jump = jump->prev;
	}
}

t_list	*ft_printp(t_list **end)
{
	t_list	*p;

	p = *end;
	while (p->prev)
	{
		if (p->content_size)
			ft_printf("L%d-%s ", p->content_size, p->content);
		p = p->prev;
	}
	return (p);
}

void	ft_printresult(t_list **res, t_hex **h, int ants)
{
	t_list	*p;
	t_list	*end;
	int		ant;

	ant = 0;
	end = ft_resetlst(res);
	while (++ant <= ants)
	{
		res[0]->next->content_size = ant;
		p = ft_printp(&end);
		ft_putchar('\n');
		ft_jumplst(&end);
	}
	p = ft_printp(&end);
	if (ft_lstsize(res) > 3)
		ft_printf("\nL%d-%s", ants, end->content);
	ft_putchar('\n');
}
