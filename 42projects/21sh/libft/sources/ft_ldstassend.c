/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldstassend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:24:09 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/15 17:15:38 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_ldstassend(t_ldst **alst, void *content, size_t content_size)
{
	t_ldst *elem_tmp;
	t_ldst *new;

	new = (t_ldst*)ft_memalloc(sizeof(t_ldst));
	new->next = NULL;
	new->prev = NULL;
	new->content = content;
	new->content_size = content_size;
	elem_tmp = *alst;
	if (elem_tmp)
	{
		new->next = elem_tmp;
		elem_tmp->prev = new;
	}
	*alst = new;
}
