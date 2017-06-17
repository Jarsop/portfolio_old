/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:27:23 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 17:39:30 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_rotjulia(t_mlx *mlx)
{
	if (mlx->x < 1.3 && mlx->y < 1.5 && mlx->x > -1.9 && mlx->y > -1.5)
		mlx->y += 0.005;
	else if (mlx->x < 1)
	{
		mlx->y = -1.5;
		mlx->x += 0.005;
	}
	else
	{
		mlx->x = -1.9;
		mlx->y = -1.5;
	}
	if (mlx->b)
	{
		mlx->c_r = mlx->x;
		mlx->c_i = mlx->y;
	}
}

void	ft_lunch(char *av)
{
	if (!ft_strcmp(av, "mandelbrot"))
		ft_mandelbrot();
	else if (!ft_strcmp(av, "mandelbrot_t"))
		ft_mandelbrot_t();
	else if (!ft_strcmp(av, "mandelbrot1"))
		ft_mandelbrot1();
	else if (!ft_strcmp(av, "julia"))
		ft_julia();
	else if (!ft_strcmp(av, "julia_t"))
		ft_julia_t();
	else if (!ft_strcmp(av, "bs"))
		ft_bship();
	if (!ft_strcmp(av, "koch"))
		ft_koch();
	if (!ft_strcmp(av, "fougere"))
		ft_fougere();
	else
		ft_error("Fractal do not exist ! :(\nUsage: ./fractol mandelbrot\n"
	"                 mandelbrot1\n"
	"                 julia\n"
	"                 bs (burningship)\n"
	"                 mandelbrot_t\n"
	"                 julia_t\n"
	"                 koch\n"
	"                 fougere\n");
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_error("Fractal do not exist ! :(\nUsage: ./fractol mandelbrot\n"
	"                 mandelbrot1\n"
	"                 julia\n"
	"                 bs (burningship)\n"
	"                 mandelbrot_t\n"
	"                 julia_t\n"
	"                 koch\n"
	"                 fougere\n");
	while (--ac)
		ft_lunch(av[ac]);
	return (0);
}
