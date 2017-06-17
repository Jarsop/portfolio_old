/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 18:13:14 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 18:56:21 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_len_ltoa(unsigned long n)
{
	int		i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_ultoa(unsigned long n)
{
	char	*ltoa;
	int		i;

	if (!(ltoa = ft_strnew(ft_len_ltoa(n))))
		return (NULL);
	i = ft_len_ltoa(n) - 1;
	while (n >= 10)
	{
		ltoa[i--] = (n % 10) + '0';
		n = n / 10;
	}
	ltoa[i--] = (n % 10) + '0';
	return (ltoa);
}
