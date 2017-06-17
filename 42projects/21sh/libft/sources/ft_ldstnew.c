/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 19:30:26 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:31:54 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_ldst	*ft_ldstnew(void const *content, size_t content_size)
{
	t_ldst	*new;

	if (!(new = (t_ldst*)ft_memalloc(sizeof(t_ldst))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	else
	{
		if (!(new->content = ft_memcpy(ft_memalloc(sizeof(content) *
		content_size), (void*)content, content_size)))
			return (NULL);
		new->content_size = content_size;
	}
	return (new);
}
