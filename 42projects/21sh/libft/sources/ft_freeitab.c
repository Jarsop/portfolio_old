/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeitab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 17:33:55 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 17:52:08 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_freeitab(int **itab, int size)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if (itab[i])
			ft_memdel((void**)&itab[i]);
	}
	if (itab)
		ft_memdel((void**)&itab);
}
