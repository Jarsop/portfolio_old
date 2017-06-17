/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:34:19 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/01 14:05:36 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(sub = (char *)ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
		sub[i++] = s[start++];
	return (sub);
}
