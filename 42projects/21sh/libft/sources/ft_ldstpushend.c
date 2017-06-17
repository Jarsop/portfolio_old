/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldstpushend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:52:08 by jgeslin           #+#    #+#             */
/*   Updated: 2016/07/09 19:06:18 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_ldstpushend(t_ldst **alst, void const *content, size_t content_size)
{
	t_ldst *new_elem;
	t_ldst *begin;

	begin = *alst;
	new_elem = ft_ldstnew(content, content_size);
	if (begin)
	{
		new_elem->next = begin;
		begin->prev = new_elem;
	}
	*alst = new_elem;
}
