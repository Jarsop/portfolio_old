/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:56:50 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/22 18:24:28 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_lstsize(t_list **alst)
{
	int		i;
	t_list	*elem_tmp;

	i = 0;
	elem_tmp = *alst;
	if (!(elem_tmp))
		return (0);
	while (elem_tmp)
	{
		elem_tmp = elem_tmp->next;
		i++;
	}
	return (i);
}
