/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 23:40:11 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 01:35:28 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_printstack(int **stack)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	ft_printf("\n|_A_| |_B_|");
	while (a < stack[D][HA] || b < stack[D][HB])
	{
		a >= stack[D][HA] ? ft_printf("\n|   |") : ft_printf("\n| %d |",
				stack[SA][a]);
		b >= stack[D][HB] ? ft_printf(" |   |") : ft_printf(" | %d |",
				stack[SB][b]);
		++a;
		++b;
	}
	ft_printf("\n\033[34mStack a : %d\033[0m\n", stack[D][HA]);
	ft_printf("\033[31mStack b : %d\033[0m\n", stack[D][HB]);
	ft_printf("\033[35mNb operates : %d\033[0m\n", stack[D][4]);
}
