/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 22:19:40 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/28 16:58:46 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_key_help(int keyhook, t_mlx *mlx)
{
	if (keyhook == 125)
	{
		mlx->x_o += 10;
		mlx->y_o += 10;
	}
	else if (keyhook == 124)
	{
		mlx->x_o += 10;
		mlx->y_o -= 10;
	}
	else if (keyhook == 123)
	{
		mlx->x_o -= 10;
		mlx->y_o += 10;
	}
	else if (keyhook == 126)
	{
		mlx->x_o -= 10;
		mlx->y_o -= 10;
	}
}

int		ft_key(int keyhook, t_mlx *mlx)
{
	if (keyhook == 53)
	{
		ft_freemap(mlx);
		ft_putendl("Done !");
		exit(0);
	}
	if (keyhook == 32)
		mlx->pz -= 2;
	if (keyhook == 2)
		mlx->pz += mlx->pz > 150 ? 100 : 2;
	if (keyhook == 69)
		mlx->zoom += 10;
	if (keyhook == 78)
		mlx->zoom -= 10;
	if (keyhook == 15)
		ft_initmlx(mlx);
	if (keyhook == 11 && !(mlx->m = 0))
		mlx->b = 1;
	if (keyhook == 46 && !(mlx->b = 0))
		mlx->m = 1;
	if (keyhook == 45 && !(mlx->b = 0))
		mlx->m = 0;
	ft_key_help(keyhook, mlx);
	return (0);
}

void	ft_rot(t_mlx *mlx, int x, int y)
{
	if (x >= mlx->x_p && y >= mlx->y_p)
	{
		mlx->x_o += 10;
		mlx->y_o += 10;
	}
	else if (x >= mlx->x_p && y <= mlx->y_p)
	{
		mlx->x_o += 10;
		mlx->y_o -= 10;
	}
	else if (x <= mlx->x_p && y >= mlx->y_p)
	{
		mlx->x_o -= 10;
		mlx->y_o += 10;
	}
	else if (x <= mlx->x_p && y <= mlx->y_p)
	{
		mlx->x_o -= 10;
		mlx->y_o -= 10;
	}
}

int		ft_mouse(int button, int x, int y, t_mlx *mlx)
{
	if (button == 1)
		ft_rot(mlx, x, y);
	return (0);
}

void	ft_mlx(t_map **map, char *av)
{
	t_mlx	mlx;

	mlx.map = map;
	mlx.x_max = map[0][0].x;
	mlx.y_max = map[0][0].y;
	ft_initmlx(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, av);
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	ft_print(&mlx);
	mlx_key_hook(mlx.win, ft_key, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop, &mlx);
	mlx_loop(mlx.mlx);
}
