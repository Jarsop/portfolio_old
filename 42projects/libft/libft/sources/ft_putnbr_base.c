/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:31:07 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:51:38 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check_base(char *base)
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

void		ft_putnbr_base(int nb, char *base)
{
	if (check_base(base) == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			if (nb == -2147483648)
			{
				ft_putnbr_base(214748364, base);
				nb = -8;
			}
			nb = -nb;
		}
		if (nb >= (int)ft_strlen(base))
		{
			ft_putnbr_base(nb / ft_strlen(base), base);
			ft_putnbr_base(nb % ft_strlen(base), base);
		}
		else
			ft_putchar(base[nb]);
	}
}
