/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:52:08 by jgeslin           #+#    #+#             */
/*   Updated: 2016/07/09 19:02:24 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstpushend(t_list **alst, void const *content, size_t content_size)
{
	t_list *new_elem;
	t_list *begin;

	begin = *alst;
	new_elem = ft_lstnew(content, content_size);
	if (begin)
		new_elem->next = begin;
	*alst = new_elem;
}
