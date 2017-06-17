/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:33:09 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 17:30:17 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_help_f(float *p, int r)
{
	if (r < 2)
	{
		p[0] = 50;
		p[1] = 0.27 * p[1];
		return (1);
	}
	else if (r < 17)
	{
		p[0] = -0.139 * p[0] + 0.263 * p[1] + 57;
		p[1] = 0.246 * p[0] + 0.224 * p[1] - 8.28;
		return (1);
	}
	else if (r < 30)
	{
		p[0] = 0.17 * p[0] - 0.215 * p[1] + 40.8;
		p[1] = 0.222 * p[0] + 0.176 * p[1] + 20.539;
		return (1);
	}
	return (0);
}

void	ft_draw_fougere(t_mlx *mlx)
{
	int		k;
	int		r;
	float	p[2];

	p[0] = 50;
	p[1] = 0;
	k = 1;
	while (k++ < mlx->iteration_max)
	{
		r = rand() % 100;
		if (ft_help_f(p, r))
			(void)k;
		else
		{
			p[0] = 0.781 * p[0] + 0.034 * p[1] + 10.75;
			p[1] = -0.032 * p[0] + 0.739 * p[1] + 62.1;
		}
		mlx->imgc[(int)(3 * (235 - p[1])) +
			(int)(3 * (p[0] - 5) + 10) * WIN_X] = r * 189979;
	}
}

int		ft_loop_fougere(t_mlx *mlx)
{
	ft_draw_fougere(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_fougere(void)
{
	t_mlx	mlx;

	ft_init_mandelbrot(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Mandelbrot");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_mandelbrot, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_fougere, &mlx);
	mlx_loop(mlx.mlx);
}
