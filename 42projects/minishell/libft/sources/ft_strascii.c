/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 16:37:04 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 16:56:35 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strascii(char *str)
{
	if (!(*str))
		return (0);
	while (*str)
	{
		if (ft_isascii(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
