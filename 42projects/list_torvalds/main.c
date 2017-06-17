/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 01:31:05 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/22 03:42:00 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_unix.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_truc	t_truc;

struct					s_truc
{
	int			val;
	t_list_head	list;
};

void		ft_init_list_head(t_list_head *list)
{
	list->next = list;
	list->prev = list;
}

static int	ft_list_add_valid(t_list_head *new, t_list_head *prev,
		t_list_head *next)
{
	return (1);
}

static void	ft_list_add_tool(t_list_head *new, t_list_head *prev,
		t_list_head *next)
{
	if (!ft_list_add_valid(new, prev, next))
		return;
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

void		ft_list_add(t_list_head *new, t_list_head *head)
{
	ft_list_add_tool(new, head, head->next);
}

t_list_head	*ft_list_for_each(t_list_head *pos, t_list_head *head)
{
	pos = pos->next;
	return (pos);
}

static int	ft_list_del_entry_valid(t_list_head *entry)
{
	return (1);
}

static void ft_list_del_tool(t_list_head *prev, t_list_head *next)
{
	next->prev = prev;
	prev->next = next;
}

void	ft_list_del_entry(t_list_head *entry)
{
	if (!ft_list_del_entry_valid(entry))
		return;
	ft_list_del_tool(entry->prev, entry->next);
}

void	ft_list_del(t_list_head *entry)
{
	ft_list_del_entry(entry);
	entry->next = NULL;
	entry->prev = NULL;
}

int		ft_list_empty(const t_list_head *head)
{
	return (head->next == head);
}

int		main(void)
{
	t_truc		*truc;
	t_truc		*truc2;
	t_truc		*res;
	t_list_head	head;
	t_list_head	*pos;

	ft_init_list_head(&head);
	truc = (t_truc*)malloc(sizeof(t_truc));
	truc->val = 42;
	ft_list_add(&truc->list, &head);
	truc2 = (t_truc*)malloc(sizeof(t_truc));
	truc2->val = 4242;
	ft_list_add(&truc2->list, &truc->list);
/*	list_for_each(pos, &head)
	{
		res = LIST_ENTRY(pos, t_truc, list);
		printf("val : %d\n", res->val);
	}*/
	//res = LIST_FIRST_ENTRY(&head, t_truc, list);
	pos = head.next;
	while (pos != &head)
	{
		res = LIST_ENTRY(pos, t_truc, list);
		printf("val : %d\n", res->val);
		pos = pos->next;
	}
	while (!ft_list_empty(&head))
	{
		res = LIST_FIRST_ENTRY(&head, t_truc, list);
		ft_list_del(&res->list);
		free(res);
	}
	return (0);
}
