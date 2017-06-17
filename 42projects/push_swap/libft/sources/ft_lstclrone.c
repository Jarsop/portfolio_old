/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclrone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:37:17 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/27 16:28:53 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "stdlib.h"

void	ft_lstclrone(t_list **begin)
{
	t_list	*lst;
	t_list	*last;
	t_list	*next;

	lst = *begin;
	while (lst)
	{
		last = lst;
		lst = lst->next;
		if (lst && lst->content == NULL)
		{
			next = lst->next;
			free(lst);
			lst = NULL;
			last->next = next;
		}
	}
}
