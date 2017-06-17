/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:22:25 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 17:09:13 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_isok(int **stack)
{
	int		i;
	int		i2;

	if (stack[D][HO] != stack[D][HA])
		return (0);
	i = 0;
	while (i < stack[D][HA])
	{
		i2 = i + 1;
		while (i2 < stack[D][HO])
		{
			if (stack[SA][i] >= stack[SA][i2])
				return (0);
			++i2;
		}
		++i;
	}
	return (1);
}

void	ft_core_rrr(int ***stack)
{
	int		a;
	int		b;

	a = stack[0][D][HA] - 1;
	b = stack[0][D][HB] - 1;
	if (a + 1 > 1 && stack[0][SA][0] > stack[0][SA][a] &&
			stack[0][SA][a] < stack[0][SA][1] && b + 1 > 1 &&
			stack[0][SB][0] < stack[0][SB][b] &&
			stack[0][SB][b] > stack[0][SB][1])
	{
		ft_rrr(stack);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_rr(int ***stack)
{
	int		a;
	int		b;

	a = stack[0][D][HA] - 1;
	b = stack[0][D][HB] - 1;
	if (a + 1 > 1 && stack[0][SA][0] > stack[0][SA][a] &&
			stack[0][SA][1] < stack[0][SA][a] && b + 1 > 1 &&
			stack[0][SB][0] < stack[0][SB][b] &&
			stack[0][SB][1] < stack[0][SB][b])
	{
		ft_rr(stack);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_ss(int ***stack)
{
	int		a;
	int		b;

	a = stack[0][D][HA] - 1;
	b = stack[0][D][HB] - 1;
	if (a + 1 > 1 && stack[0][SA][0] > stack[0][SA][1] && b + 1 > 1 &&
			stack[0][SB][0] < stack[0][SB][1])
	{
		ft_ss(stack);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}
