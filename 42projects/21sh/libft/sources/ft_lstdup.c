/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 03:44:52 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 19:11:53 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list	*ft_lstdup(t_list **alst)
{
	t_list	*new;
	t_list	*src;

	new = NULL;
	src = *alst;
	while (src)
	{
		if (src->content)
			ft_lstpushback(&new, src->content, ft_strlen(src->content) + 1);
		src = src->next;
	}
	return (new);
}
