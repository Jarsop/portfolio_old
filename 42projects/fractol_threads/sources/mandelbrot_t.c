/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:33:09 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 17:37:07 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_th_mandelbrot(t_th *th, int x, int y)
{
	double	tmp;
	double	c[2];
	double	z_r;
	double	z_i;
	int		i;

	i = 0;
	c[0] = (x + th->c_th * 100) / th->zoom + th->x1 + th->x_o;
	c[1] = y / th->zoom + th->y1 + th->y_o;
	z_r = 0;
	z_i = 0;
	while (z_r * z_r + z_i * z_i < 4 && i < th->i_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c[0];
		z_i = 2 * z_i * tmp + c[1];
		++i;
	}
	if (i != th->i_max)
		th->cp[x + y * th->x] = i * 189979;
}

void	*ft_draw_mandelbrot_t(void *tho)
{
	t_th	*th;
	int		x;
	int		y;

	th = (t_th*)tho;
	if (!(th->cp = (int*)ft_memalloc(sizeof(int) * (th->x * th->y))))
		pthread_exit(NULL);
	x = -1;
	while (++x < th->x)
	{
		y = -1;
		while (++y < th->y)
			ft_th_mandelbrot(th, x, y);
	}
	pthread_exit(NULL);
}

void	ft_pthread_m(t_mlx *mlx, t_th *th)
{
	int		i;

	i = -1;
	while (++i < NB_THREADS)
	{
		th[i].c_th = i;
		th[i].i_max = mlx->iteration_max;
		th[i].x1 = mlx->x1;
		th[i].y1 = mlx->y1;
		th[i].x_o = mlx->x_o;
		th[i].y_o = mlx->y_o;
		th[i].x = WIN_X / NB_THREADS;
		th[i].y = WIN_Y;
		th[i].zoom = mlx->zoom;
		pthread_create(&th[i].th, NULL, ft_draw_mandelbrot_t, (void*)&th[i]);
	}
}

int		ft_loop_mandelbrot_t(t_mlx *mlx)
{
	t_th	th[NB_THREADS];
	int		i;
	int		j;
	int		k;

	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	ft_pthread_m(mlx, th);
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(th[i].th, NULL);
	i = -1;
	while (++i < NB_THREADS)
	{
		j = -1;
		while (++j < th[i].x)
		{
			k = -1;
			while (++k < WIN_Y)
				mlx->imgc[i * 100 + j + k * WIN_X] = th[i].cp[j + k * th[i].x];
		}
		free(th[i].cp);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_mandelbrot_t(void)
{
	t_mlx	mlx;

	ft_init_mandelbrot(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Mandelbrot thread");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_mandelbrot, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_mandelbrot_t, &mlx);
	mlx_loop(mlx.mlx);
}
