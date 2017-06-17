/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:05:36 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:46:36 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_strlen_base(int l, char *str, char *base, char a)
{
	int		i;
	int		count;

	if (l == 1)
	{
		i = 0;
		while (str[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	if (l == 2)
	{
		count = 0;
		while (base[count] != '\0')
		{
			if (a == base[count])
				return (count);
			count++;
		}
		return (-1);
	}
	return (0);
}

static int	ft_check_base(char *base)
{
	size_t	i;

	i = 0;
	if ((*base == '\0' || *(base + 1) == '\0') || (base[i] < 48 || \
				(base[i] > 57 && base[i] < 65) || (base[i] > 90 && base[i] < 97)
				|| base[i] > 122))
		return (0);
	while (*base != '\0')
	{
		i = 1;
		while (base[i] != '\0')
		{
			if (*base == base[i])
				return (0);
			if ((base[i] < 48 || (base[i] > 57 && base[i] < 65) || \
						(base[i] > 90 && base[i] < 97) || base[i] > 122))
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

char		*ft_itoa_base(long nb, char *base)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	if (!(str = ft_strnew(60)) || (ft_check_base(base) == 0))
		return (NULL);
	if (nb == 0 || nb < -2147483648 || nb > 2147483647 || \
			ft_strlen_base(1, base, "a", 'a') < 2)
		return (str);
	if (nb < 0)
	{
		j = 1;
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = base[nb % ft_strlen_base(1, base, "a", 'a')];
		nb = nb / ft_strlen_base(1, base, "a", 'a');
		i++;
	}
	if (j == 1)
		str[i] = '-';
	return (ft_strrev(ft_strdupclr(str)));
}
