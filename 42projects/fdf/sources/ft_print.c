/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 08:00:29 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/10 16:07:33 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_print_point(t_mlx *mlx, int x, int y)
{
	mlx->z = mlx->map[y][x].z;
	mlx->color = mlx->map[y][x].color;
	mlx->x_p = (-mlx->y_c * y + mlx->x_c * x) * mlx->zoom + mlx->x_o;
	mlx->y_p = (-((float)mlx->z / mlx->pz) + (mlx->y_c / 2) * y +
			(mlx->x_c / 2) * x) * mlx->zoom + mlx->y_o;
	if (mlx->x_max == 1 && mlx->y_max == 1)
		ft_to_do(mlx, mlx->x_p, mlx->y_p, mlx->m ? LIGHT_GREEN : WHITE);
	if (x < mlx->x_max - 1 && x < WIN_X)
	{
		mlx->x_n = mlx->map[y][x + 1].z;
		mlx->x_np = (-mlx->y_c * y + mlx->x_c * (x + 1)) * mlx->zoom +
						mlx->x_o;
		mlx->y_np = (-((float)mlx->x_n / mlx->pz) + (mlx->y_c / 2) * y +
				(mlx->x_c / 2) * (x + 1)) * mlx->zoom + mlx->y_o;
		ft_draw(mlx->x_np, mlx->y_np, mlx, 1);
	}
	if (y < mlx->y_max - 1 && y < WIN_Y)
	{
		mlx->y_n = mlx->map[y + 1][x].z;
		mlx->x_np = (-mlx->y_c * (y + 1) + mlx->x_c * x) * mlx->zoom + mlx->x_o;
		mlx->y_np = (-((float)mlx->y_n / mlx->pz) + (mlx->y_c / 2) *
						(y + 1) + (mlx->x_c / 2) * x) * mlx->zoom + mlx->y_o;
		ft_draw(mlx->x_np, mlx->y_np, mlx, 0);
	}
}

void	ft_to_do(t_mlx *mlx, int x, int y, int color)
{
	if (y >= WIN_Y || x >= WIN_X || x < 0 || y < 0)
		return ;
	if (!mlx->b && mlx->color >= 0)
		mlx->imgc[x + y * WIN_X] = mlx->color;
	else
		mlx->imgc[x + y * WIN_X] = color;
}

void	ft_print(t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y < mlx->y_max)
	{
		x = -1;
		while (++x < mlx->x_max)
			ft_print_point(mlx, x, y);
	}
	ft_print_color(mlx->x_t, mlx->y_t, mlx, 0);
}
