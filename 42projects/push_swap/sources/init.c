/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 23:58:32 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/29 19:48:22 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_errps(void)
{
	ft_fprintf(2, "Error\n");
	exit(0);
}

static int	ft_check(char *av)
{
	char	*test;
	long	val;

	test = NULL;
	val = ft_atol_base(av, "0123456789");
	if (val > 2147483647 || val < -2147483648)
		ft_errps();
	if (ft_strcmp((test = ft_itoa(val)), av))
	{
		if (test)
			free(test);
		ft_errps();
	}
	if (test)
		free(test);
	return ((int)val);
}

static void	ft_checkdbl(char **av, int ac)
{
	int		i;
	int		i2;

	i = 0;
	while (++i < ac)
	{
		i2 = i;
		while (++i2 < ac)
		{
			if (!ft_strcmp(av[i], av[i2]))
				ft_errps();
		}
	}
}

int			**ft_initps(int ac, char **av)
{
	int		**stack;
	int		i;

	i = 0;
	ft_checkdbl(av, ac);
	if (!(stack = (int**)ft_memalloc((sizeof(int*)) * 3)))
		ft_errps();
	if (!(stack[D] = (int*)ft_memalloc((sizeof(int)) * 13)))
		ft_errps();
	if (!(stack[SA] = (int*)ft_memalloc((sizeof(int)) * ac - 1)))
		ft_errps();
	if (!(stack[SB] = (int*)ft_memalloc((sizeof(int)) * ac - 1)))
		ft_errps();
	while (++i < ac)
		stack[SA][i - 1] = ft_check(av[i]);
	stack[D][HO] = ac - 1;
	stack[D][HA] = ac - 1;
	return (stack);
}
