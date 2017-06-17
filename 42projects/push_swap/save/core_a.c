/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 00:11:39 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 22:17:17 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_isoka(int **stack)
{
	int		i;
	int		i2;

	i = 0;
	while (i < stack[D][HA])
	{
		i2 = i + 1;
		while (i2 < stack[D][HA])
		{
			if (stack[SA][i] >= stack[SA][i2])
				return (0);
			++i2;
		}
		++i;
	}
	return (1);
}

void	ft_core_rra(int ***stack)
{
	int		a;

	a = stack[0][D][HA] - 1;
	if (a + 1 > 1 && (stack[0][SA][0] > stack[0][SA][a] &&
				stack[0][SA][a] < stack[0][SA][1]))
	{
		ft_rra(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_ra(int ***stack)
{
	int		a;

	a = stack[0][D][HA] - 1;
	if (a + 1 > 1 && stack[0][SA][0] > stack[0][SA][a] &&
			stack[0][SA][1] < stack[0][SA][a])
	{
		ft_ra(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_sa(int ***stack)
{
	int		a;

	a = stack[0][D][HA] - 1;
	if (a + 1 > 1 && stack[0][SA][0] > stack[0][SA][1])
	{
		if (a + 1 > 2  && stack[0][SA][0] < stack[0][SA][a])
			ft_sa(*stack, 0);
		else if (a + 1 > 1)
			ft_sa(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_pa(int ***stack)
{
	while (stack[0][D][HB] && ft_isoka(*stack))
	{
		if (stack[0][D][HB] > 1 && ft_isokb(*stack))
			ft_pa(*stack);
		else if (stack[0][D][HB] > 0)
			ft_pa(*stack);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}
