/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 01:54:30 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 17:26:55 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_core_preva(int ***stack)
{
	int		a;

	a = stack[0][D][HA] - 1;
	if (a + 1 > 5 && stack[0][SA][a - 1] > stack[0][SA][a] &&
				stack[0][SA][a] > stack[0][SA][0])
	{
		ft_rra(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_rra(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_sa(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_ra(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_ra(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_core_prevb(int ***stack)
{
	int		b;

	b = stack[0][D][HB] - 1;
	if (b + 1 > 5 && stack[0][SB][b - 1] < stack[0][SB][b] &&
				stack[0][SB][b] < stack[0][SB][0])
	{
		ft_rrb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_rrb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_sb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_rb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
		ft_rb(*stack, 0);
		(stack[0][D][V]) ? ft_printstack(*stack) : 0;
	}
}

void	ft_ss(int ***stack)
{
	stack[0][D][4] -= 1;
	ft_sa(*stack, 1);
	ft_sb(*stack, 1);
	ft_isok(*stack) || stack[0][D][V] ? ft_putstr("ss\n") : ft_putstr("ss ");
}

void	ft_rr(int ***stack)
{
	stack[0][D][4] -= 1;
	ft_ra(*stack, 1);
	ft_rb(*stack, 1);
	ft_isok(*stack) || stack[0][D][V] ? ft_putstr("rr\n") : ft_putstr("rr ");
}

void	ft_rrr(int ***stack)
{
	stack[0][D][4] -= 1;
	ft_rra(*stack, 1);
	ft_rrb(*stack, 1);
	ft_isok(*stack) || stack[0][D][V] ? ft_putstr("rrr\n") : ft_putstr("rrr ");
}
