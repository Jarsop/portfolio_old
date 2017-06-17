/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 11:16:16 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 18:03:09 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_printparse(t_list **rec)
{
	t_list	*t;

	t = *rec;
	while (t)
	{
		ft_printf("%s\n", (char*)t->content);
		t = t->next;
	}
	ft_putchar('\n');
}

void	ft_check_link(t_list **rec, t_list *t)
{
	t_list	*tmp;
	char	*s;
	int		c;
	int		n;

	tmp = *rec;
	while (tmp)
	{
		n = ft_strlen(t->content);
		if (ft_strlen(tmp->content) > n + 1 &&
			((ft_strnstr(tmp->content, t->content, n) ||
			ft_strnrstr(tmp->content, t->content, n))) &&
		(((char*)tmp->content)[n] == '-' ||
		((char*)tmp->content)[ft_strlen(tmp->content) - n - 1] == '-'))
			t->content_size += 1;
		tmp = tmp->next;
	}
}

void	ft_find_link(t_list **rec)
{
	t_list	*t;

	t = *rec;
	while (t && ((char*)t->content)[0] == '#')
		t = t->next;
	t = t->next;
	while (t)
	{
		ft_check_link(rec, t);
		t = t->next;
	}
}

void	ft_print_lnk(t_hex **hex)
{
	t_hex	*h;
	int		n;

	h = *hex;
	while (h)
	{
		n = 0;
		if (h->se)
			ft_printf("\n\033[31mRoom\033[0m [\033[1;33m%s\033[0m]"
			" <-- \033[1;31m%s\033[0m :\n", h->name, h->se == 1 ?
			"\033[1;32mstart\033[35m" : "\033[1;31mend\033[35m");
		else
			ft_printf("\n\033[31mRoom\033[0m [\033[1;33m%s\033[0m] :\n",
			h->name);
		while (n < h->n)
		{
			if (h->next[n])
				ft_printline(h, n);
			++n;
		}
		h = h->prev;
	}
	ft_putchar('\n');
}

void	ft_inithex(t_list **rec, int ants, int v)
{
	t_list	*t;
	t_hex	*hex;
	char	*s;

	t = *rec;
	hex = NULL;
	ft_find_link(rec);
	while (t)
	{
		s = (char*)t->content;
		if (t->content_size && s[0] != 'L' && s[0] != '#')
			ft_hexpushback(&hex, ((char*)(t->content)), t->content_size);
		t = t->next;
	}
	if (ft_start(&hex, rec) && ft_end(&hex, rec) && ft_hexok(&hex))
	{
		ft_nbrhex(&hex, rec);
		ft_relink(&hex, rec);
		if (v)
			ft_print_lnk(&hex);
		ft_resolve(&hex, ants);
	}
	ft_freehex(hex);
}
