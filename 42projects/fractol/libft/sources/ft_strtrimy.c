/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:42:00 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/19 14:37:49 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <string.h>

char	*ft_strtrimy(char const *s, char y)
{
	int		start;
	int		end;
	int		len;
	char	*ret;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] == y)
		start++;
	end = ft_strlen(s) - 1;
	while (s[end] == y)
		end--;
	len = end - start + 1;
	if (len < 0)
		len = 0;
	if (!(ret = ft_strsub(s, start, len)))
		return (NULL);
	return (ret);
}
