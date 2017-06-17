/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:40:59 by jgeslin           #+#    #+#             */
/*   Updated: 2016/01/15 04:04:25 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	if (!s1)
		return (NULL);
	dst = ft_strnew(sizeof(*s1) * (ft_strlen(s1)));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, (void*)s1, ft_strlen(s1));
	return (dst);
}
