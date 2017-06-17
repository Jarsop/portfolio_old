/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 23:25:35 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/30 23:54:42 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw_mandelbrot1(t_mlx *mlx)
{
	double	tmp;
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
		{
			i = 0;
			mlx->c_r = x / mlx->zoom + mlx->x1 + mlx->x_o;
			mlx->c_i = y / mlx->zoom + mlx->y1 + mlx->y_o;
			mlx->z_r = 0;
			mlx->z_i = 0;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4 && i < mlx->iteration_max)
			{
				tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = -2 * mlx->z_i * tmp + mlx->c_i;
				++i;
			}
			if (i != mlx->iteration_max)
				mlx->imgc[x + y * WIN_X] = i * 189979;
			else
				mlx->imgc[x + y * WIN_X] = 0;
		}
	}
}

int		ft_loop_mandelbrot1(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	ft_draw_mandelbrot1(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_mandelbrot1(void)
{
	t_mlx	mlx;

	ft_init_mandelbrot1(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Mandelbrot1");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_mandelbrot, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_mandelbrot1, &mlx);
	mlx_loop(mlx.mlx);
}
