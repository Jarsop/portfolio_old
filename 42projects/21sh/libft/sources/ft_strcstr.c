/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:25:52 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/05 20:32:26 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../includes/libft.h"

char	*ft_strcstr(const char *s1, const char *s2, char c)
{
	int i;
	int j;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i] != '\0' && s1[i] != c)
	{
		j = 0;
		while ((s1[i + j] != '\0') && (s1[i + j] == s2[j]))
		{
			j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
