/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:17:54 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 18:47:48 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static long	ft_find_base(char ch, char *base)
{
	long	count;

	count = 0;
	while (base[count] != '\0')
	{
		if (ch == base[count])
			return (count);
		count++;
	}
	return (-1);
}

static int	ft_check_base(char *base)
{
	int		i;

	i = 0;
	while (*base != '\0')
	{
		i = 1;
		while (base[i] != '\0')
		{
			if (*base == base[i])
				return (0);
			if (base[i] < 33 || base[i] > 122)
				return (0);
			if (base[i] == '-' || base[i] == '+')
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

long		ft_atol_base(char *str, char *base)
{
	long	number;
	long	base_nbr;
	int		negatif;

	negatif = 1;
	if (!ft_check_base(base))
		return (0);
	if (*str == '-' || *str == '+')
	{
		negatif = (*str == '-') ? -1 : 1;
		str++;
	}
	base_nbr = ft_strlen(base);
	number = 0;
	while (*str != '\0')
	{
		if (*str == '-' || *str == '+')
			return (number * negatif);
		number *= base_nbr;
		if (ft_find_base(*str, base) == -1)
			return (0);
		number += (ft_find_base(*str, base));
		str++;
	}
	return (number * negatif);
}
