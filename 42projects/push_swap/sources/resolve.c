/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 04:13:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/29 19:46:15 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_minmaxa(int ***stack)
{
	int		i;

	i = 0;
	stack[0][D][MINA] = stack[0][SA][i];
	stack[0][D][MAXA] = stack[0][SA][i];
	while (i < stack[0][D][HA])
	{
		if (stack[0][SA][i] > stack[0][D][MAXA])
		{
			stack[0][D][MAXA] = stack[0][SA][i];
			stack[0][D][HMAXA] = i;
		}
		else if (stack[0][SA][i] < stack[0][D][MINA])
		{
			stack[0][D][MINA] = stack[0][SA][i];
			stack[0][D][HMINA] = i;
		}
		++i;
	}
}

static void	ft_res(int ***stack)
{
	int		d;

	while (!ft_isok(*stack))
	{
		ft_core_preva(stack);
		ft_core_sa(stack);
		d = stack[0][D][HMINA] > stack[0][D][HA] / 2 ? 1 : 0;
		while (stack[0][SA][0] != stack[0][D][MINA])
		{
			if (d)
				ft_core_rra(stack);
			else
				ft_core_ra(stack);
		}
		if (stack[0][D][HB] && stack[0][SB][0] < stack[0][SA][0] &&
				ft_isoka(*stack))
			ft_core_pa(stack);
		if (!ft_isok(*stack) && (!stack[0][D][HB] || (stack[0][D][HB] &&
						stack[0][SA][0] > stack[0][SB][0])))
		{
			ft_core_pb(stack);
			ft_minmaxa(stack);
		}
	}
	(stack[0][D][V]) ? ft_putstr("\033[32m\nDone!\033[0m\n") : 0;
}

static void	ft_freeps(int **stack)
{
	free(stack[SA]);
	free(stack[SB]);
}

void		ft_ps(int ac, char **av, int v)
{
	int		**stack;
	int		i;

	i = -1;
	stack = ft_initps(ac, av);
	if (v)
		stack[D][V] = 1;
	(stack[D][V]) ? ft_putstr("\033[33mInitial Stack :\033[0m") : 0;
	(stack[D][V]) ? ft_printstack(stack) : 0;
	ft_minmaxa(&stack);
	ft_res(&stack);
	ft_freeps(stack);
}
