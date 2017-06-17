/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstrct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:25:52 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/03 15:40:22 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int		ft_strnstrct(const char *s1, const char *s2, size_t n)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	if (s2[i] == '\0')
		return (0);
	while (s1[i] != '\0' && n > 0)
	{
		j = 0;
		while ((s1[i + j] != '\0') && (s1[i + j] == s2[j]))
		{
			j++;
			if (s2[j] == '\0')
				++c;
		}
		--n;
		++i;
	}
	return (c);
}
