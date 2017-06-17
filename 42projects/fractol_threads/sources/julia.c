/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 08:30:34 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 15:41:08 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_draw_julia(t_mlx *mlx)
{
	double	tmp;
	int		xy[2];
	int		i;
	size_t	r;

	xy[0] = -1;
	while (++xy[0] < WIN_X)
	{
		xy[1] = -1;
		while (++xy[1] < WIN_Y && !(i = 0))
		{
			mlx->z_r = xy[0] / mlx->zoom + mlx->x1 + mlx->x_o;
			mlx->z_i = xy[1] / mlx->zoom + mlx->y1 + mlx->y_o;
			while (mlx->z_r * mlx->z_r + mlx->z_i * mlx->z_i < 4 &&
					i < mlx->iteration_max)
			{
				tmp = mlx->z_r;
				mlx->z_r = mlx->z_r * mlx->z_r - mlx->z_i * mlx->z_i + mlx->c_r;
				mlx->z_i = 2 * mlx->z_i * tmp + mlx->c_i;
				++i;
			}
			if (i != mlx->iteration_max)
				mlx->imgc[xy[0] + xy[1] * WIN_X] = i * 189979;
		}
	}
}

int		ft_loop_julia(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	ft_draw_julia(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

int		ft_julia_hook(int x, int y, t_mlx *mlx)
{
	if (x <= WIN_X && y <= WIN_Y && x > 0 && y > 0 && !mlx->b)
	{
		mlx->c_r = (float)(x + 400 - WIN_X) / 300;
		mlx->c_i = (float)(y + 320 - WIN_Y) / 300;
	}
	return (1);
}

void	ft_julia(void)
{
	t_mlx	mlx;

	ft_init_julia(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Julia");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 6, (1L << 6), ft_julia_hook, &mlx);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_julia, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_julia, &mlx);
	mlx_loop(mlx.mlx);
}
