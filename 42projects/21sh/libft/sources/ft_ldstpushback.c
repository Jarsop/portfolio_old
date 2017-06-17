/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldstpushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:49:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/15 14:23:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_ldstpushback(t_ldst **alst, void const *content, size_t content_size)
{
	t_ldst *elem_tmp;
	t_ldst *new;

	new = ft_ldstnew(content, content_size);
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
