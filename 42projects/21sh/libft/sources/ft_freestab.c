/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:12:46 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/19 15:09:01 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_freestab(char **stab)
{
	int		i;

	i = -1;
	while (stab[++i])
	{
		if (stab[i])
			ft_memdel((void**)&stab[i]);
	}
	if (stab[i])
		ft_memdel((void**)&stab[i]);
	if (stab)
		ft_memdel((void**)&stab);
}
