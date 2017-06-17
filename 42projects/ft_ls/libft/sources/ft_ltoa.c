/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:13:14 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 18:55:26 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_len_ltoa(long n)
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

char		*ft_ltoa(long n)
{
	char	*ltoa;
	int		i;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(ltoa = ft_strnew(ft_len_ltoa(n))))
		return (NULL);
	i = ft_len_ltoa(n) - 1;
	if (n < 0)
	{
		ltoa[0] = '-';
		n *= -1;
		i = ft_len_ltoa(n);
	}
	while (n >= 10)
	{
		ltoa[i--] = (n % 10) + '0';
		n = n / 10;
	}
	ltoa[i--] = (n % 10) + '0';
	return (ltoa);
}
