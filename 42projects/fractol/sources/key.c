/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:50:11 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/30 23:10:21 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_key_mandelbrot(int keyhook, t_mlx *mlx)
{
	if (keyhook == 53)
	{
		ft_putendl("Done !");
		exit (0);
	}
	else if (keyhook == 24)
		mlx->zoom += 10;
	else if (keyhook == 27)
		mlx->zoom -= 10;
	else if (keyhook == 15)
		ft_init_mandelbrot(mlx);
	else if (keyhook == 125)
		mlx->y_o -= 0.05;
	else if (keyhook == 124)
		mlx->x_o -= 0.05;
	else if (keyhook == 123)
		mlx->x_o += 0.05;
	else if (keyhook == 126)
		mlx->y_o += 0.05;
	else if (keyhook == 34)
		mlx->iteration_max += 10;
	else if (keyhook == 40)
		mlx->iteration_max -= 10;
	return (1);
}

int		ft_key_julia(int keyhook, t_mlx *mlx)
{
	if (keyhook == 53)
	{
		ft_putendl("Done !");
		exit (0);
	}
	else if (keyhook == 24)
		mlx->zoom += 0.05;
	else if (keyhook == 27)
		mlx->zoom -= 0.05;
	else if (keyhook == 15)
		ft_init_julia(mlx);
	else if (keyhook == 125)
		mlx->y_o -= 0.05;
	else if (keyhook == 124)
		mlx->x_o -= 0.05;
	else if (keyhook == 123)
		mlx->x_o += 0.05;
	else if (keyhook == 126)
		mlx->y_o += 0.05;
	else if (keyhook == 34)
		mlx->iteration_max += 10;
	else if (keyhook == 40)
		mlx->iteration_max -= 10;
	else if (keyhook == 11)
	{
		if (mlx->b)
			mlx->b = 0;
		else
			mlx->b = 1;
	}
	return (1);
}
