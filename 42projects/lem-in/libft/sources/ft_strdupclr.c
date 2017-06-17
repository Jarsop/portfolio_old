/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:17:24 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:53:25 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strdupclr(const char *s1)
{
	char	*dst;

	dst = ft_strnew(sizeof(*s1) * (ft_strlen(s1)));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, (void*)s1, ft_strlen(s1));
	free((void*)s1);
	s1 = NULL;
	return (dst);
}
