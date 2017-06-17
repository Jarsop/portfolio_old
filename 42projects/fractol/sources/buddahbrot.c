/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddahbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 10:20:11 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/31 16:45:29 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw_buddahbrot(t_mlx *mlx)
{
	double	tmp;
	double	eps;
	double	fact;
	size_t	x;
	size_t	y;
	int		i;
	int		j;
	int		cp[WIN_X * WIN_Y];

	i = 0;
	srand(1);
	ft_bzero(&cp, sizeof(int) * (WIN_X * WIN_Y));
	eps = 4 / WIN_X;
	fact = 4 / ((float)RAND_MAX + 1.0f);
	j = -1;
		while (++j < 1500000)
		{
			mlx->c_r = rand() / fact + mlx->x_o;
			mlx->c_i = rand() / fact + mlx->y_o;
			mlx->z_r = 0;
			mlx->z_i = 0;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4.0f && i < mlx->iteration_max)
			{
				tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2.0f * mlx->z_i * tmp + mlx->c_i;
				++i;
			}
			if (i < mlx->iteration_max && i > 50)
				//mlx->imgc[x + y * WIN_X] = i * 189979;
			{
				j = 0;
				mlx->z_r = mlx->c_r;
				mlx->z_i = mlx->c_i;
				while (j++ < i -1)
				{
					x = (mlx->z_r + 2.0f) / eps;
					y = (mlx->z_i + 2.0f) / eps;
					cp[x + y * WIN_X]++;
					tmp = mlx->z_r;
					mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
					mlx->z_i = 2.0f * mlx->z_i * tmp + mlx->c_i;
				}
			}
		}
	j = 0;
	i = -1;
	while (++i < WIN_X * WIN_Y)
	{
		if (cp[i] > j)
			j = cp[i];
	}
	i = -1;
	while (++i < WIN_X * WIN_Y)
	{
		mlx->imgc[3 * i] = 255 * cp[i] / j;
		mlx->imgc[3 * i + 1] = 255 * cp[i] / j;
		mlx->imgc[3 * i + 2] = 255 * cp[i] / j;
	}
	/*x = -1;
	while (++x < WIN_X)
	{
		y = -1;
		while (++y < WIN_Y)
		{
			i = 0;
			x1 = rand();
			y1 = rand();
			mlx->z_r = 0;
			mlx->z_i = 0;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4 && i < mlx->iteration_max)
			{
				tmp = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + x1;
				mlx->z_i = 2 * mlx->z_r * mlx->z_i + y1;
				mlx->z_r = tmp;
				++i;
			}
			if (i < mlx->iteration_max && i > 5)
			{
				ft_putendl("yolo");
				mlx->imgc[x1 + y1 * WIN_X] = i * 255 / mlx->iteration_max;
			}
		}
	}*/
}

int		ft_loop_buddahbrot(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	ft_draw_buddahbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_buddahbrot(void)
{
	t_mlx	mlx;

	ft_init_buddahbrot(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Buddahbrot");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_mandelbrot, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_buddahbrot, &mlx);
	mlx_loop(mlx.mlx);
}
