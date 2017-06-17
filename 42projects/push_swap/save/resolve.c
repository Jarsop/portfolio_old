/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 04:13:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 20:43:50 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_sort_b(int ***stack)
{
	ft_core_prevb(stack);
	ft_core_rrr(stack);
	ft_core_rrb(stack);
	ft_core_rr(stack);
	ft_core_rb(stack);
	ft_core_ss(stack);
	ft_core_sb(stack);
	ft_core_pa(stack);
}

static void	ft_res(int ***stack)
{
	while (!ft_isok(*stack))
	{
		ft_core_preva(stack);
		ft_core_rrr(stack);
		ft_core_rra(stack);
		ft_core_rr(stack);
		ft_core_ra(stack);
		ft_core_ss(stack);
		ft_core_sa(stack);
		ft_core_pb(stack);
		ft_core_pa(stack);
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
	ft_res(&stack);
	ft_freeps(stack);
}
