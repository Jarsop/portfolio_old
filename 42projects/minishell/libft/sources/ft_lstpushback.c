/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:49:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/20 16:23:31 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstpushback(t_list **alst, void const *content, size_t content_size)
{
	t_list *elem_tmp;
	t_list *new;

	new = ft_lstnew(content, content_size);
	elem_tmp = *alst;
	if (elem_tmp)
	{
		while (elem_tmp->next)
			elem_tmp = elem_tmp->next;
		elem_tmp->next = new;
		new->prev = elem_tmp;
	}
	else
		*alst = new;
}
