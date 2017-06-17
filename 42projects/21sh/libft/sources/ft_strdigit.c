/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 17:53:43 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/17 17:53:57 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strdigit(char *str)
{
	if (!(*str))
		return (1);
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			str++;
		else
			return (0);
	}
	return (1);
}