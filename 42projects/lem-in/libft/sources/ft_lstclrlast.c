/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclrlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/27 15:37:17 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/22 03:18:08 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "stdlib.h"

void	ft_lstclrlast(t_list **begin)
{
	t_list	*lst;
	t_list	*last;

	lst = *begin;
	while (lst->next)
	{
		last = lst;
		lst = lst->next;
	}
	if (lst && lst->content)
	{
		free(lst->content);
		free(lst);
		last->next = NULL;
		lst = NULL;
	}
}
