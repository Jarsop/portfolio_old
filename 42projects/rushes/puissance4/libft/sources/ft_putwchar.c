/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:01:00 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/27 20:01:20 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/libft.h"

static void	ft_help(unsigned int c)
{
	write(1, &c, 1);
}

void		ft_putwchar(unsigned int c)
{
	if (c < 128)
		ft_help(c);
	else if (c < 2048)
	{
		ft_help(192 | (c >> 6));
		ft_help(128 | (c & 63));
	}
	else if (c < 65536)
	{
		ft_help(224 | (c >> 12));
		ft_help(128 | ((c >> 6) & 63));
		ft_help(128 | (c & 63));
	}
	else if (c < 1114112)
	{
		ft_help(240 | (c >> 18));
		ft_help(128 | ((c >> 12) & 63));
		ft_help(128 | ((c >> 6) & 63));
		ft_help(128 | (c & 63));
	}
}
