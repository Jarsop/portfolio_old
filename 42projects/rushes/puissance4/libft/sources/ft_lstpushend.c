/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:52:08 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:49:19 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstpushend(t_list **alst, void const *content, size_t content_size)
{
	t_list *new_elem;

	new_elem = ft_lstnew(content, content_size);
	new_elem->next = *alst;
	*alst = new_elem;
}
