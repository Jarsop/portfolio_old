/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:56:50 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:49:30 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstsize(t_list *alst)
{
	int		i;
	t_list	*elem_tmp;

	i = 0;
	elem_tmp = alst;
	if (alst == 0)
		return (0);
	while (elem_tmp->next != 0)
	{
		elem_tmp = elem_tmp->next;
		i++;
	}
	i++;
	return (i);
}
