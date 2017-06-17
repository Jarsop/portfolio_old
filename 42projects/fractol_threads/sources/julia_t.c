/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 08:30:34 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 20:45:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_th_julia(t_th *th, int x, int y, int col)
{
	double	tmp;
	double	z_r;
	double	z_i;
	int		i;
	int		c;

	i = 0;
	c = 255;
	z_r = (x + th->c_th * 100) / th->zoom + th->x1 + th->x_o;
	z_i = y / th->zoom + th->y1 + th->y_o;
	while (z_r * z_r + z_i * z_i < 4 && i < th->i_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + th->c_r;
		z_i = 2 * z_i * tmp + th->c_i;
		++i;
		c += 20;
	}
	if (i != th->i_max)
	{
		if (col)
			th->cp[x + y * th->x] = i * 189979;
		else
			th->cp[x + y * th->x] = i * (0xFFFFFF ^ c);
	}
}

void	*ft_draw_julia_t(void *tho)
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
			ft_th_julia(th, x, y, th->c);
	}
	pthread_exit(NULL);
}

void	ft_pthread_j(t_mlx *mlx, t_th *th)
{
	int		i;

	i = -1;
	while (++i < NB_THREADS)
	{
		th[i].c = mlx->c;
		th[i].c_th = i;
		th[i].i_max = mlx->iteration_max;
		th[i].x1 = mlx->x1;
		th[i].y1 = mlx->y1;
		th[i].x_o = mlx->x_o;
		th[i].y_o = mlx->y_o;
		th[i].x = WIN_X / NB_THREADS;
		th[i].y = WIN_Y;
		th[i].c_r = mlx->c_r;
		th[i].c_i = mlx->c_i;
		th[i].zoom = mlx->zoom;
		pthread_create(&th[i].th, NULL, ft_draw_julia_t, (void*)&th[i]);
	}
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(th[i].th, NULL);
}

int		ft_loop_julia_t(t_mlx *mlx)
{
	t_th	th[NB_THREADS];
	int		i;
	int		j;
	int		k;

	if (mlx->t)
		ft_rotjulia(mlx);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	ft_pthread_j(mlx, th);
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

void	ft_julia_t(void)
{
	t_mlx	mlx;

	ft_init_julia(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Julia thread");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 6, (1L << 6), ft_julia_hook, &mlx);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_julia, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_julia_t, &mlx);
	mlx_loop(mlx.mlx);
}
