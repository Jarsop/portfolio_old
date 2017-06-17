/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 16:27:23 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/30 21:42:21 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_zoom_out(int x, int y, t_mlx *mlx)
{
	if (mlx->zoom > 250)
	{
		mlx->zoom /= 2;
		mlx->tmpx = mlx->x1 + x * (mlx->x2 - mlx->x1) / WIN_X;
		mlx->tmpy = mlx->y1 + y * (mlx->y2 - mlx->y1) / WIN_Y;
		mlx->tmpx2 = mlx->x1;
		mlx->tmpy2 = mlx->y1;
		mlx->x1 = mlx->tmpx - (mlx->x2 - mlx->x1);
		mlx->x2 = mlx->tmpx + (mlx->x2 - mlx->tmpx2);
		mlx->y1 = mlx->tmpy - (mlx->y2 - mlx->y1);
		mlx->y2 = mlx->tmpy + (mlx->y2 - mlx->tmpy2);
	}
}

void	ft_zoom_in(int x, int y, t_mlx *mlx)
{
	mlx->zoom *= 2;
	mlx->tmpx = mlx->x1 + x * (mlx->x2 - mlx->x1) / WIN_X;
	mlx->tmpy = mlx->y1 + y * (mlx->y2 - mlx->y1) / WIN_Y;
	mlx->tmpx2 = mlx->x1;
	mlx->tmpy2 = mlx->y1;
	mlx->x1 = mlx->tmpx - (mlx->x2 - mlx->x1) / 4;
	mlx->x2 = mlx->tmpx + (mlx->x2 - mlx->tmpx2) / 4;
	mlx->y1 = mlx->tmpy - (mlx->y2 - mlx->y1) / 4;
	mlx->y2 = mlx->tmpy + (mlx->y2 - mlx->tmpy2) / 4;
}

int		ft_mouse_hook(int keycode, int x, int y, t_mlx *mlx)
{
	if (y > 0)
	{
		if (keycode == 1 || keycode == 5)
			ft_zoom_in(x, y, mlx);
		if (keycode == 2 || keycode == 4)
			ft_zoom_out(x, y, mlx);
	}
	return (1);
}
