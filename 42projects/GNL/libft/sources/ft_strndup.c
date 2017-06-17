/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:40:59 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:55:01 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*dst;

	dst = ft_strnew(sizeof(*s1) * n);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, (void*)s1, n);
	return (dst);
}
