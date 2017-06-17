/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 13:32:43 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 22:13:57 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static char	*ft_calc_dtoa(char *tmp)
{
	int				e;
	double			m;
	int				i;
	int				p;
	unsigned long	dizaine;

	p = 1;
	i = 11;
	m = 0;
	e = ft_atol_base(ft_strsub(tmp, 1, 11), "01");
	e -= 1023;
	dizaine = 10;
	return (tmp);
}

char		*ft_dtoa(double dbl)
{
	char	*final;
	long	e;

	if (!(final = ft_memalloc(sizeof(char) * 65)))
		return (NULL);
	e = dbl;
	final = ft_strwjoin(final, ft_ltoa(e), 2);
	final[ft_strlen(final)] = '.';
	dbl = dbl - e;
	if (dbl < 0)
		dbl *= -1;
	while (dbl < 9)
	{
		dbl *= 10;
		if ((int)dbl == 0)
			final = ft_strwjoin(final, "0", 0);
	}
	if ((int)(dbl * 10) % 10 > 4)
		++dbl;
	e = dbl;
	final = ft_strwjoin(final, ft_ltoa(e), 2);
	return (final);
}
