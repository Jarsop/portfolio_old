/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:40:59 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/15 23:09:55 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	dst = ft_strnew(ft_strlen(s1));
	if (!dst)
		return (NULL);
	ft_strncpy(dst, s1, ft_strlen(s1));
	return (dst);
}
