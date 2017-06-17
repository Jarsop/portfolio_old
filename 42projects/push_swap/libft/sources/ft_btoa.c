/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:32:07 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 19:00:49 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*malloc_strbytes(int type, int w)
{
	char	*str;

	if (!(str = ft_strnew((type * 8) * w)))
		return (NULL);
	ft_memset(str, '0', (type * 8) * w);
	return (str);
}

char		*ft_btoa(void *data, int type, int w)
{
	unsigned long	mask;
	unsigned long	nbr;
	char			*str;
	char			*d;
	unsigned long	jim;

	str = malloc_strbytes(type, w);
	d = str;
	jim = ft_ulpower(2, 8 * type - 1);
	while (w--)
	{
		mask = jim;
		nbr = type * 8;
		while (nbr--)
		{
			if (mask & *(unsigned long *)data)
				*str = '1';
			mask >>= 1;
			++str;
		}
		data += type;
	}
	return (str - (str - d));
}
