/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:34:19 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/15 21:59:44 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || start > ft_strlen(s))
		return (NULL);
	if (!(sub = (char *)ft_strnew(len)))
		return (NULL);
	sub = ft_strncpy(sub, &s[start], len);
	return (sub);
}
