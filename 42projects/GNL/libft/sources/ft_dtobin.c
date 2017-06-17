/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtobin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:49:18 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 18:54:03 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static unsigned long	*ft_popdbl(double dbl, unsigned long *t)
{
	int				i;
	unsigned long	tmp[64];
	unsigned long	som;
	unsigned long	*ptr;
	unsigned long	res;

	i = -1;
	som = 1;
	ptr = (unsigned long *)(&dbl);
	while (++i < 64)
	{
		tmp[i] = som;
		som *= 2;
	}
	i = -1;
	while (++i <= 64)
	{
		res = *ptr & tmp[i];
		if (res == tmp[i])
			t[i] = 1;
	}
	return (t);
}

char					*ft_dtobin(double dbl)
{
	unsigned long	*t;
	int				i;
	char			*s;
	char			*f;

	i = -1;
	if (!(t = ft_memalloc(sizeof(unsigned long) * 64)))
		return (NULL);
	if (!(s = ft_memalloc(sizeof(char) * 65)))
		return (NULL);
	t = ft_popdbl(dbl, t);
	while (++i < 64)
		s[i] = (t[i] + 48);
	free(t);
	f = s;
	s = ft_strrev(s);
	free(f);
	return (s);
}
