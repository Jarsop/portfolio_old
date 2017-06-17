/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwnjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 15:44:22 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/29 16:06:20 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strwnjoin(char const *s1, char const *s2, size_t len, size_t a)
{
	char	*ts1;
	char	*ts2;
	char	*join;

	ts1 = a == 0 || a == 2 ? (char*)s1 : NULL;
	ts2 = a == 1 || a == 2 ? (char*)s2 : NULL;
	join = ft_strnjoin(s1, s2, len);
	if (a == 0)
		free(ts1);
	else if (a == 1)
		free(ts2);
	else if (a == 2)
	{
		free(ts1);
		free(ts2);
	}
	return (join);
}
