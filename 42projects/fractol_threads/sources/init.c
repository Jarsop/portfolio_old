/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:34:05 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 16:58:48 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_mandelbrot(t_mlx *mlx)
{
	mlx->x1 = -2.1;
	mlx->x2 = 0.6;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->x_o = 0;
	mlx->y_o = 0;
	mlx->zoom = 250;
	mlx->b = 1;
	mlx->iteration_max = 100;
	mlx->im_x = (mlx->x2 - mlx->x1) * mlx->zoom + 150;
	mlx->im_y = (mlx->y2 - mlx->y1) * mlx->zoom;
}

void	ft_init_julia(t_mlx *mlx)
{
	mlx->x1 = -1.6;
	mlx->x2 = 1;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->x_o = 0;
	mlx->y_o = 0;
	mlx->zoom = 250;
	mlx->iteration_max = 100;
	mlx->im_x = (mlx->x2 - mlx->x1) * mlx->zoom + 150;
	mlx->im_y = (mlx->y2 - mlx->y1) * mlx->zoom;
	mlx->b = 1;
	mlx->t = 0;
	mlx->x = -1.6;
	mlx->y = -1.2;
	mlx->c_r = 0.285;
	mlx->c_i = 0.01;
}

void	ft_init_bship(t_mlx *mlx)
{
	mlx->x1 = -2.1;
	mlx->x2 = 0.6;
	mlx->y1 = -1.5;
	mlx->y2 = 1.2;
	mlx->zoom = 250;
	mlx->iteration_max = 20;
	mlx->im_x = (mlx->x2 - mlx->x1) * mlx->zoom + 300;
	mlx->im_y = (mlx->y2 - mlx->y1) * mlx->zoom;
}

void	ft_init_mandelbrot1(t_mlx *mlx)
{
	mlx->x1 = -2.1;
	mlx->x2 = 1;
	mlx->y1 = -1.2;
	mlx->y2 = 1.2;
	mlx->zoom = 250;
	mlx->im_x = (mlx->x2 - mlx->x1) * mlx->zoom + 50;
	mlx->im_y = (mlx->y2 - mlx->y1) * mlx->zoom;
	mlx->iteration_max = 90;
}
