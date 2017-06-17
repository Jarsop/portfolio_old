/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:54:06 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/27 15:27:26 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstend(t_list **alst, t_list *new)
{
	t_list	*tmp;
	t_list	*m;

	if (*alst && new)
	{
		m = *alst;
		while (m)
		{
			tmp = m;
			m = m->next;
		}
		tmp->next = new;
	}
	else
		*alst = new;
}
