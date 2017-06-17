/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 23:13:46 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/10 15:22:44 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw(int x, int y, t_mlx *mlx, int c)
{
	mlx->x_t = mlx->x_p;
	mlx->y_t = mlx->y_p;
	mlx->dx = abs(x - mlx->x_p);
	mlx->dy = abs(y - mlx->y_p);
	mlx->sx = mlx->x_p < x ? 1 : -1;
	mlx->sy = mlx->y_p < y ? 1 : -1;
	mlx->err = (mlx->dx > mlx->dy ? mlx->dx : -(mlx->dy)) / 2;
	while (!(mlx->y_t == y && mlx->x_t == x))
	{
		ft_print_color(mlx->x_t, mlx->y_t, mlx, c);
		mlx->e2 = mlx->err;
		if (mlx->e2 > -(mlx->dx))
		{
			mlx->err -= mlx->dy;
			mlx->x_t += mlx->sx;
		}
		if (mlx->e2 < mlx->dy)
		{
			mlx->err += mlx->dx;
			mlx->y_t += mlx->sy;
		}
	}
}

void	ft_initmlx(t_mlx *mlx)
{
	int		tmp;

	tmp = mlx->x_max + mlx->y_max;
	if (tmp < 10)
		tmp = 10;
	mlx->zoom = WIN_Y / (tmp / 10);
	mlx->x_o = WIN_X / 5 * 2.5;
	mlx->y_o = WIN_Y / 5 * 2;
	mlx->x_c = 0.1;
	mlx->y_c = 0.1;
	mlx->pz = 50;
	mlx->b = 0;
	mlx->m = 0;
}

int		ft_loop(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	ft_print(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_print_color(int x, int y, t_mlx *mlx, int c)
{
	int v;

	if (c > 0)
		v = (mlx->z > mlx->x_n) ? x : mlx->x_n;
	else
		v = (mlx->z > mlx->y_n) ? x : mlx->y_n;
	if (mlx->b || v == 0)
		ft_to_do(mlx, x, y, mlx->m ? DARK_BLUE : RED);
	else if (v < 2)
		ft_to_do(mlx, x, y, mlx->m ? KING_BLUE : DARK_GREEN);
	else if (v < 4)
		ft_to_do(mlx, x, y, mlx->m ? DARK_GREEN : RED);
	else if (v < 8)
		ft_to_do(mlx, x, y, mlx->m ? KING_GREEN : BROWN);
	else if (v < 16)
		ft_to_do(mlx, x, y, mlx->m ? DARK_BROWN : GREY);
	else if (v < 32)
		ft_to_do(mlx, x, y, mlx->m ? BROWN : LIGHT_GREEN);
	else if (v < 64)
		ft_to_do(mlx, x, y, mlx->m ? KING_GREEN : SKIN);
	else if (v < 128)
		ft_to_do(mlx, x, y, mlx->m ? KING_GREEN : LIGHT_BLUE);
	else
		ft_to_do(mlx, x, y, mlx->m ? DARK_GREY : WHITE);
}
