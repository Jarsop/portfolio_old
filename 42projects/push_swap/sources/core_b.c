/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:12:06 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/29 19:47:55 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_isokb(int **stack)
{
	int		i;
	int		i2;

	i = 0;
	while (i < stack[D][HA])
	{
		i2 = i + 1;
		while (i2 < stack[D][HA])
		{
			if (stack[SA][i] <= stack[SA][i2])
				return (0);
			++i2;
		}
		++i;
	}
	return (1);
}

void	ft_core_rrb(int ***stack)
{
	int		b;

	b = stack[0][D][HB] - 1;
	if (b + 1 > 1 && stack[0][SB][0] < stack[0][SB][b] &&
			stack[0][SB][b] > stack[0][SB][1])
	{
		ft_rrb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_rb(int ***stack)
{
	int		b;

	b = stack[0][D][HB] - 1;
	if (b + 1 > 1 && stack[0][SB][0] < stack[0][SB][b] &&
			stack[0][SB][1] > stack[0][SB][b])
	{
		ft_rb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_sb(int ***stack)
{
	int		b;

	b = stack[0][D][HB] - 1;
	if (b + 1 > 1 && stack[0][SB][0] < stack[0][SB][1])
	{
		if (b + 1 > 2 && stack[0][SB][0] > stack[0][SB][b])
			ft_sb(*stack, 0);
		else if (b + 1 > 1)
			ft_sb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_pb(int ***stack)
{
	int		a;

	a = stack[0][D][HA] - 1;
	if (a + 1 > 1)
	{
		ft_pb(*stack);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}
