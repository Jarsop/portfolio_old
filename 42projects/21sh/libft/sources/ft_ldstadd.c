/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 19:30:09 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:30:11 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_ldstadd(t_ldst **alst, t_ldst *new)
{
	if (*alst && new)
	{
		new->next = *alst;
		(*alst)->prev = new;
		*alst = new;
	}
	else
		*alst = new;
}
