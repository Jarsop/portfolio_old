/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:27:23 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/31 00:01:07 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_lunch(char *av)
{
	if (!ft_strcmp(av, "mandelbrot"))
		ft_mandelbrot();
	else if (!ft_strcmp(av, "mandelbrot1"))
		ft_mandelbrot1();
	else if (!ft_strcmp(av, "julia"))
		ft_julia();
	else if (!ft_strcmp(av, "buddahbrot"))
		ft_buddahbrot();
	else if (!ft_strcmp(av, "bs"))
		ft_bship();
	else
		ft_error("Fractal do not exist ! :(\nUsage: ./fractol mandelbrot\n"
						"                 mandelbrot1\n"
					 	"                 julia\n"
						"                 bs (burningship)\n");
}

int		main(int ac, char **av)
{
	while (--ac)
		ft_lunch(av[ac]);
	return (0);
}
