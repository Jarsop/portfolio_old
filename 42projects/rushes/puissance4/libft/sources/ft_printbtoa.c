/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbtoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:41:09 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 18:55:49 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_printbtoa(char *str, int type)
{
	int		i;

	i = type * 8;
	while (*str)
	{
		ft_putchar(*str);
		i--;
		if (i == 0 && (i = type * 8))
			ft_putchar('\n');
		++str;
	}
}
