/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:41:29 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/21 22:06:36 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strnrstr(const char *s1, const char *s2, size_t n)
{
	char				*s;

	s = (char*)&s1[ft_strlen(s1) - n];
	if (!ft_strcmp(s, s2))
		return (s);
	return (NULL);
}
