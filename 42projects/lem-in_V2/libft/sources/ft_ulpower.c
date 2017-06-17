/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulpower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 19:11:07 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/03 17:02:34 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_ulpower(unsigned long nbr, unsigned long power)
{
	if (power == 0)
		return (1);
	else
		return ((nbr) * ft_ulpower(nbr, power - 1));
}
