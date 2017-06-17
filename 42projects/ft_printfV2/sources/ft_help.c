/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 20:45:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 22:06:54 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

unsigned long	ft_help_pop(t_conv *t_mask, char **tmp)
{
	if (ft_strstr(*tmp, t_mask[51].conv))
		g_mask |= t_mask[51].mask;
	free(*tmp);
	return (g_mask);
}

char			*ft_help_point2(void)
{
	g_p = 1;
	if ((g_mask & MASK_O || g_mask & MASK_OO) && g_mask & MASK_HASH)
		return (ft_strdup("0"));
	if ((g_mask & MASK_P) && g_mask & MASK_HASH)
		return (ft_strdup("0x"));
	return (ft_strdup("\0"));
}
