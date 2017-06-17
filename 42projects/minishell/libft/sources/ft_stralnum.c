/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stralnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 04:20:32 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/12 04:20:51 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_stralnum(char *str)
{
	if (!(*str))
		return (0);
	while (*str)
	{
		if (ft_isalnum(*str))
			str++;
		else
			return (0);
	}
	return (1);
}
