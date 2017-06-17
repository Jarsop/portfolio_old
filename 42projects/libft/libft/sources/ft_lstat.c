/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 23:01:59 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:47:16 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstat(t_list *alst, size_t nbr)
{
	size_t	i;
	t_list	*elem_tmp;

	i = 0;
	elem_tmp = alst;
	if (elem_tmp == 0)
		return (0);
	while (i < nbr)
	{
		elem_tmp = elem_tmp->next;
		i++;
	}
	return (elem_tmp);
}
