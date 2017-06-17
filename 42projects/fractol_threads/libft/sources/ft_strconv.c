/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:54:16 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:36:40 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_strconv2(char *ftmp)
{
	char	*conv;
	int		i;
	int		j;

	i = 0;
	conv = "hhlljz%";
	while (ftmp[i])
	{
		j = 0;
		while (conv[j])
		{
			if (ftmp[i] == conv[j])
				return (i + 1);
			++j;
		}
		++i;
	}
	return (0);
}

int			ft_strconv(char *ftmp)
{
	char	*conv;
	int		i;
	int		j;

	i = 0;
	conv = "cCdDiuUsSoOpxXeEaAfFgGnbrk%";
	while (ftmp[i])
	{
		j = 0;
		while (conv[j])
		{
			if (ftmp[i] == conv[j])
				return (i + 1);
			++j;
		}
		++i;
	}
	i = ft_strconv2(ftmp);
	return (i);
}
