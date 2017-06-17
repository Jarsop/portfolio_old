/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:22:55 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/02 11:21:07 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*((unsigned char*)dst) = *((unsigned char*)src);
		if (((unsigned char)c) == *((unsigned char*)src))
		{
			dst++;
			return (dst);
		}
		dst++;
		src++;
		n--;
	}
	return (NULL);
}
