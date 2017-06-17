/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 01:42:11 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/11 21:38:05 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_wchart4(unsigned int wc)
{
	unsigned char	octet[5];
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	o1 = ((wc >> 18) << 29) >> 29;
	o2 = ((wc >> 12) << 26) >> 26;
	o3 = ((wc >> 6) << 26) >> 26;
	o4 = (wc << 26) >> 26;
	octet[0] = (g_wc3 >> 24) | o1;
	octet[1] = ((g_wc3 << 8) >> 24) | o2;
	octet[2] = ((g_wc3 << 16) >> 24) | o3;
	octet[3] = ((g_wc3 << 24) >> 24) | o4;
	octet[4] = 0;
	return (ft_strdup((char*)octet));
}

static char	*ft_wchart3(unsigned int wc)
{
	unsigned char	octet[4];
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;

	o1 = ((wc >> 12) << 28) >> 28;
	o2 = ((wc >> 6) << 26) >> 26;
	o3 = (wc << 26) >> 26;
	octet[0] = (g_wc2 >> 16) | o1;
	octet[1] = ((g_wc2 << 16) >> 24) | o2;
	octet[2] = ((g_wc2 << 24) >> 24) | o3;
	octet[3] = 0;
	return (ft_strdup((char*)octet));
}

static char	*ft_wchart2(unsigned int wc)
{
	unsigned char	octet[3];
	unsigned char	o1;
	unsigned char	o2;

	o1 = ((wc >> 6) << 27) >> 27;
	o2 = (wc << 26) >> 26;
	octet[0] = (g_wc1 >> 8) | o1;
	octet[1] = ((g_wc1 << 24) >> 24) | o2;
	octet[2] = 0;
	return (ft_strdup((char*)octet));
}

static char	*ft_wchart1(unsigned int wc)
{
	unsigned char	octet[2];

	octet[0] = wc;
	octet[1] = 0;
	return (ft_strdup((char*)octet));
}

char		*ft_getwschart(unsigned int wc)
{
	g_wc1 = 49280;
	g_wc2 = 14712960;
	g_wc3 = 4034953344;
	if (!(wc & 0xFFFFFF80))
		return (ft_strdupclr(ft_wchart1(wc)));
	else if (!(wc & 0xFFFFF800))
		return (ft_strdupclr(ft_wchart2(wc)));
	else if (!(wc & 0xFFFF0000))
		return (ft_strdupclr(ft_wchart3(wc)));
	else
		return (ft_strdupclr(ft_wchart4(wc)));
}
