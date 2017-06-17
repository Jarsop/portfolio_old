/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 01:58:40 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/21 22:02:33 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_initse(t_hex **hex, int se, char *str, t_list **rec)
{
	t_hex	*h;
	t_list	*t;

	h = *hex;
	t = *rec;
	while (h && ft_strcmp(h->name, str))
		h = h->prev;
	h->se += se;
}

int		ft_end(t_hex **hex, t_list **rec)
{
	t_list	*t;

	t = *rec;
	while (t)
	{
		if (!ft_strcmp("##end", t->content))
		{
			if (!t->next || !t->next->content_size ||
					!ft_strcmp("##start", t->content))
			{
				ft_error("Error\n");
				return (0);
			}
			t = t->next;
			break ;
		}
		t = t->next;
	}
	if (t)
		ft_initse(hex, 2, t->content, rec);
	else
		return (0);
	return (1);
}

int		ft_start(t_hex **hex, t_list **rec)
{
	t_list	*t;

	t = *rec;
	while (t)
	{
		if (!ft_strcmp("##start", t->content))
		{
			if (!t->next || !t->next->content_size ||
					!ft_strcmp("##end", t->content))
			{
				ft_error("Error\n");
				return (0);
			}
			t = t->next;
			break ;
		}
		t = t->next;
	}
	if (t)
		ft_initse(hex, 1, t->content, rec);
	else
		return (0);
	return (1);
}

int		ft_verbose(t_list **res)
{
	t_list	*t;

	t = *res;
	while (t)
	{
		if (!ft_strcmp(t->content, "##verbose"))
			return (1);
		t = t->next;
	}
	return (0);
}
