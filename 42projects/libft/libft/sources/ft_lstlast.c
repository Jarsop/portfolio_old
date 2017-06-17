/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:57:59 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:48:26 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstlast(t_list *alst)
{
	t_list	*elem_tmp;

	elem_tmp = alst;
	while (elem_tmp->next != 0)
	{
		elem_tmp = elem_tmp->next;
	}
	return (elem_tmp);
}
