/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 23:33:33 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/04 23:34:43 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	char	*a;
	char	*b;
	size_t	i;

	a = dest;
	b = src;
	i = size;
	if (i != 0)
	{
		while (--i != 0)
		{
			if ((*a++ = *b++) == '\0')
				break ;
		}
	}
	if (i == 0)
	{
		if (size != 0)
			*a = '\0';
		while (*b++)
			;
	}
	return (b - src - 1);
}
