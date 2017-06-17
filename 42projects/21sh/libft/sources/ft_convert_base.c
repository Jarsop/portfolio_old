/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:27:48 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:45:01 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	return (ft_itoa_base(ft_atoi_base(nbr, base_from), base_to));
}
