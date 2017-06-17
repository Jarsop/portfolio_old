/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:42:00 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:56:39 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strtrimy(char const *s, char y)
{
	size_t	i;
	size_t	j;
	size_t	c;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == y)
		i++;
	j = 0;
	c = 0;
	while (s[c])
	{
		if (s[c] != y)
		{
			c++;
			j = c;
		}
		else
			c++;
	}
	if (!j)
		return (ft_strdup(""));
	return (ft_strsub(s, i, j - i));
}
