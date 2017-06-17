/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 15:28:15 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:17:05 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdlib.h>

void	ft_pstr(char *format)
{
	g_l = -1;
	while (*format != '.')
		++format;
	++format;
	g_l = ft_atoi(format);
}
