/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:50:03 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:50:02 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	unsigned char	u1;
	unsigned char	u2;

	tmp1 = (unsigned char*)s1;
	tmp2 = (unsigned char*)s2;
	while (n-- > 0)
	{
		u1 = (unsigned char)*tmp1++;
		u2 = (unsigned char)*tmp2++;
		if (u1 != u2)
			return (u1 - u2);
	}
	return (0);
}
