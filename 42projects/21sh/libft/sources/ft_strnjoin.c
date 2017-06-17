/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 20:52:54 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/19 16:29:02 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	str =
		ft_strnew(ft_strlen(s1) + len);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strncat(str, s2, len);
	return (str);
}
