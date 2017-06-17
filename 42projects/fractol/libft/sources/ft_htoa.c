/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:13:14 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/11 20:25:38 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_len_htoa(short n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n--;
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_htoa(short n)
{
	char	*htoa;
	int		i;

	if (n == -32768)
		return (ft_strdup("-32768"));
	if (!(htoa = ft_strnew(ft_len_htoa(n))))
		return (NULL);
	i = ft_len_htoa(n) - 1;
	if (n < 0)
	{
		htoa[0] = '-';
		n *= -1;
		i = ft_len_htoa(n);
	}
	while (n >= 10)
	{
		htoa[i--] = (n % 10) + '0';
		n = n / 10;
	}
	htoa[i--] = (n % 10) + '0';
	return (htoa);
}
