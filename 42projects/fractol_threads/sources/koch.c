/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   koch.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 00:37:40 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 17:34:07 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_dot(int x, int y, int color, int *b)
{
	b[x + y * WIN_X] = color;
}

void	ft_drawline(int *koch, int color, int *b)
{
	double	xy[4];
	int		m;

	xy[0] = koch[0];
	xy[1] = koch[1];
	xy[2] = koch[2] - xy[0];
	xy[3] = koch[3] - xy[1];
	m = MAX(ABS(xy[2]), ABS(xy[3]));
	xy[2] /= m;
	xy[3] /= m;
	while (m-- >= 0)
	{
		ft_dot((unsigned int)xy[0], (unsigned int)xy[1], color, b);
		xy[0] += xy[2];
		xy[1] += xy[3];
	}
}

void	ft_draw_koch(t_mlx *mlx, int *koch, int col)
{
	int		**t;
	int		i;

	if (mlx->iteration_max > 0)
	{
		i = -1;
		if (!(t = (int**)ft_memalloc(sizeof(int*) * 4)))
			exit(-1);
		while (++i < 4)
		{
			if (!(t[i] = (int*)ft_memalloc(sizeof(int) * 4)))
				exit(-1);
		}
		ft_init_tk(t, koch);
		--mlx->iteration_max;
		ft_draw_koch(mlx, t[0], col);
		ft_draw_koch(mlx, t[1], col + 1);
		ft_draw_koch(mlx, t[2], col + 1);
		ft_draw_koch(mlx, t[3], col);
		while (--i > 0)
			free(t[i]);
		++mlx->iteration_max;
	}
	else
		ft_drawline(koch, 255 * (col + 1) * 75, mlx->imgc);
}

int		ft_loop_koch(t_mlx *mlx)
{
	int		koch[4];
	int		i;

	i = -1;
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, WIN_X, WIN_Y);
	while (++i < 3)
	{
		ft_init_koch(mlx, i);
		ft_init_tkm(mlx, koch);
		ft_draw_koch(mlx, koch, 0);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	return (0);
}

void	ft_koch(void)
{
	t_mlx	mlx;

	ft_init_mlxk(&mlx);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, WIN_X, WIN_Y, "Flocon de Koch");
	mlx.img = mlx_new_image(mlx.mlx, WIN_X, WIN_Y);
	mlx.imgc = (int*)mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.sl, &mlx.e);
	mlx_hook(mlx.win, 2, (1L << 0), ft_key_koch, &mlx);
	mlx_mouse_hook(mlx.win, ft_mouse_hook, &mlx);
	mlx_loop_hook(mlx.mlx, ft_loop_koch, &mlx);
	mlx_loop(mlx.mlx);
}
