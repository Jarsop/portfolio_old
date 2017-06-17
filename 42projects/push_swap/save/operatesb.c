/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatesb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 03:59:01 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 01:33:07 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sb(int **stack, int p)
{
	stack[D][4] += 1;
	ft_iswap(&stack[SB][0], &stack[SB][1]);
	if (!p)
		stack[D][V] ? ft_putstr("sb\n") : ft_putstr("sb ");
}

void	ft_rb(int **stack, int p)
{
	int		i;
	int		c;

	c = 0;
	stack[D][4] += 1;
	i = stack[SB][0];
	while (c < stack[D][HB])
	{
		ft_iswap(&stack[SB][c], &stack[SB][c + 1]);
		++c;
	}
	stack[SB][stack[D][HB] - 1] = i;
	if (!p)
		stack[D][V] ? ft_putstr("rb\n") : ft_putstr("rb ");
}

void	ft_rrb(int **stack, int p)
{
	int		i;
	int		h;

	h = stack[D][HB];
	stack[D][4] += 1;
	i = stack[SB][h - 1];
	while (--h)
		ft_iswap(&stack[SB][h], &stack[SB][h - 1]);
	stack[SB][0] = i;
	if (!p)
		stack[D][V] ? ft_putstr("rrb\n") : ft_putstr("rrb ");
}

void	ft_pb(int **stack)
{
	int		c;

	stack[D][HB] += 1;
	stack[D][4] += 1;
	c = stack[D][HB];
	while (c > 0)
	{
		ft_iswap(&stack[SB][c], &stack[SB][c - 1]);
		--c;
	}
	ft_iswap(&stack[SB][0], &stack[SA][0]);
	c = 0;
	while (c < stack[D][HA])
	{
		ft_iswap(&stack[SA][c], &stack[SA][c + 1]);
		++c;
	}
	if (stack[D][HA] > 0)
		stack[D][HA] -= 1;
	stack[D][V] ? ft_putstr("pb\n") : ft_putstr("pb ");
}
