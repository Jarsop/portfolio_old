/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:48:59 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:56:28 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	c;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = 0;
	c = 0;
	while (s[c])
	{
		if (s[c] != ' ' && s[c] != '\n' && s[c] != '\t')
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
