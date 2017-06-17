/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 23:49:15 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/28 01:14:45 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_fprintf(2, "Error\n");
	else
	{
		if (!ft_strncmp(av[1], "-v", 2))
			ft_ps(ac - 1, &av[1], 1);
		else
			ft_ps(ac, av, 0);
	}
	return (0);
}
