/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatesa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 03:59:01 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/29 18:22:44 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(int **stack, int p)
{
	stack[D][C] += 1;
	ft_iswap(&stack[SA][0], &stack[SA][1]);
	if (!p)
		ft_isok(stack) || stack[D][V] ? ft_putstr("sa\n") : ft_putstr("sa ");
}

void	ft_ra(int **stack, int p)
{
	int		i;
	int		c;

	c = 0;
	i = stack[SA][0];
	stack[D][C] += 1;
	while (c < stack[D][HA])
	{
		ft_iswap(&stack[SA][c], &stack[SA][c + 1]);
		++c;
	}
	stack[SA][stack[D][HA] - 1] = i;
	if (!p)
		ft_isok(stack) || stack[D][V] ? ft_putstr("ra\n") : ft_putstr("ra ");
}

void	ft_rra(int **stack, int p)
{
	int		i;
	int		h;

	h = stack[D][HA];
	i = stack[SA][h - 1];
	stack[D][C] += 1;
	while (--h)
		ft_iswap(&stack[SA][h], &stack[SA][h - 1]);
	stack[SA][0] = i;
	if (!p)
		ft_isok(stack) || stack[D][V] ? ft_putstr("rra\n") : ft_putstr("rra ");
}

void	ft_pa(int **stack)
{
	int		c;

	stack[D][HA] += 1;
	c = stack[D][HA];
	stack[D][C] += 1;
	while (c > 0)
	{
		ft_iswap(&stack[SA][c], &stack[SA][c - 1]);
		--c;
	}
	ft_iswap(&stack[SB][0], &stack[SA][0]);
	c = 0;
	while (c < stack[D][HB])
	{
		ft_iswap(&stack[SB][c], &stack[SB][c + 1]);
		++c;
	}
	if (stack[D][HB])
		stack[D][HB] -= 1;
	ft_isok(stack) || stack[D][V] ? ft_putstr("pa\n") : ft_putstr("pa ");
}
