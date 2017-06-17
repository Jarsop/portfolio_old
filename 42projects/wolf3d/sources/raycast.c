/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:48:26 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 18:48:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void	ft_initray(t_w *e, int x)
{
	e->player.hcamera = 2 * x / (double)(WIN_X) - 1;
	e->r.pos.x = e->player.pos.x;
	e->r.pos.y = e->player.pos.y;
	e->r.dir.x = e->player.dir.x + e->r.plane.x * e->player.hcamera;
	e->r.dir.y = e->player.dir.y + e->r.plane.y * e->player.hcamera;
	e->r.posmap.x = (int)e->r.pos.x;
	e->r.posmap.y = (int)e->r.pos.y;
	e->r.disd.x = sqrt(1 + (e->r.dir.y * e->r.dir.y)
			/ (e->r.dir.x * e->r.dir.x));
	e->r.disd.y = sqrt(1 + (e->r.dir.x * e->r.dir.x)
			/ (e->r.dir.y * e->r.dir.y));
	e->player.hit = 0;
}

static void	ft_raydir(t_w *e)
{
	if (e->r.dir.x < 0)
	{
		e->player.step.x = -1;
		e->r.sidedist.x = (e->r.pos.x - e->r.posmap.x) * e->r.disd.x;
	}
	else
	{
		e->player.step.x = 1;
		e->r.sidedist.x = (e->r.posmap.x + 1.0 - e->r.pos.x) * e->r.disd.x;
	}
	if (e->r.dir.y < 0)
	{
		e->player.step.y = -1;
		e->r.sidedist.y = (e->r.pos.y - e->r.posmap.y) * e->r.disd.y;
	}
	else
	{
		e->player.step.y = 1;
		e->r.sidedist.y = (e->r.posmap.y + 1.0 - e->r.pos.y) * e->r.disd.y;
	}
}

static void	ft_dda(t_w *e)
{
	while (e->player.hit == 0)
	{
		if (e->r.sidedist.x < e->r.sidedist.y)
		{
			e->r.sidedist.x += e->r.disd.x;
			e->r.posmap.x += e->player.step.x;
			e->player.wallside = 0;
		}
		else
		{
			e->r.sidedist.y += e->r.disd.y;
			e->r.posmap.y += e->player.step.y;
			e->player.wallside = 1;
		}
		if (e->map.map[e->r.posmap.x][e->r.posmap.y] > 0)
			e->player.hit = 1;
	}
}

static void	ft_compute(t_w *e)
{
	if (e->player.wallside == 0)
		e->player.distwall = (e->r.posmap.x - e->r.pos.x
					+ (1 - e->player.step.x) / 2) / e->r.dir.x;
	else
		e->player.distwall = (e->r.posmap.y - e->r.pos.y
					+ (1 - e->player.step.y) / 2) / e->r.dir.y;
	e->r.lheight = (int)(WIN_Y / e->player.distwall);
	e->r.ystart = -(e->r.lheight) / 2 + WIN_Y / 2;
	if (e->r.ystart < 0)
		e->r.ystart = 0;
	e->r.yend = e->r.lheight / 2 + WIN_Y / 2;
	if (e->r.yend >= WIN_Y)
		e->r.yend = WIN_Y - 1;
}

int			ft_loop_hook(t_w *e)
{
	t_rgb	c;
	int		x;

	if ((int)e->player.pos.x == 36 && (int)e->player.pos.y == 24)
	{
		ft_freeitab(e->map.map, e->map.h);
		ft_map(e, "./maps/map2");
	}
	ft_bzero(e->m.imgc, WIN_X * WIN_Y);
	ft_drawspace(e);
	x = 0;
	ft_get_timeframe(e);
	while (x < WIN_X)
	{
		ft_initray(e, x);
		ft_raydir(e);
		ft_dda(e);
		ft_compute(e);
		!e->offtex ? ft_colors(e, &c) : ft_tex(e, x);
		ft_drawline(x, e, &c);
		x++;
	}
	ft_move(e);
	mlx_put_image_to_window(e->m.mlx, e->m.win, e->m.img, 0, 0);
	return (0);
}
