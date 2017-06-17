/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:13:14 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:46:23 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_len_itoa(int n)
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

char		*ft_itoa(int n)
{
	char	*itoa;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(itoa = ft_strnew(ft_len_itoa(n))))
		return (NULL);
	i = ft_len_itoa(n) - 1;
	if (n < 0)
	{
		itoa[0] = '-';
		n *= -1;
		i = ft_len_itoa(n);
	}
	while (n >= 10)
	{
		itoa[i--] = (n % 10) + '0';
		n = n / 10;
	}
	itoa[i--] = (n % 10) + '0';
	return (itoa);
}
