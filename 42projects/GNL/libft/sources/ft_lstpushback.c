/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:49:37 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:49:06 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstpushback(t_list **alst, void const *content, size_t content_size)
{
	t_list *elem_tmp;

	elem_tmp = *alst;
	while (elem_tmp->next != 0)
	{
		elem_tmp = elem_tmp->next;
	}
	elem_tmp->next = ft_lstnew(content, content_size);
}
