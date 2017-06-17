/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:53:49 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 18:49:59 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void	ft_set(t_rgb *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

static void	ft_mlx_image_put_pixel(t_mlx *i, t_ci p, t_rgb *c)
{
	i->imgc[p.y * i->sl + i->bpp / 8 * p.x] =
		mlx_get_color_value(i->mlx, c->b);
	i->imgc[p.y * i->sl + i->bpp / 8 * p.x + 1] =
		mlx_get_color_value(i->mlx, c->g);
	i->imgc[p.y * i->sl + i->bpp / 8 * p.x + 2] =
		mlx_get_color_value(i->mlx, c->r);
}

static void	ft_offtex(t_w *e, t_rgb *c, t_rgb *sky, t_ci *p)
{
	ft_set(sky, 0, 153, 255);
	p->y = 0;
	while (p->y < e->r.ystart)
	{
		ft_mlx_image_put_pixel(&(e->m), p[0], sky);
		p->y++;
	}
	p->y = e->r.ystart;
	while (p->y < e->r.yend)
	{
		ft_mlx_image_put_pixel(&(e->m), p[0], c);
		p->y++;
	}
}

void		ft_drawline(int x, t_w *e, t_rgb *c)
{
	t_ci	p;
	t_rgb	sky;

	p.x = x;
	if (!e->offtex)
		ft_offtex(e, c, &sky, &p);
	e->offtex ? ft_set(&sky, 51, 51, 51) : ft_set(&sky, 153, 0, 0);
	p.y = e->r.yend;
	while (p.y < WIN_Y)
	{
		ft_mlx_image_put_pixel(&(e->m), p, &sky);
		p.y++;
	}
}

void		ft_colors(t_w *e, t_rgb *c)
{
	if (e->player.wallside == 0)
	{
		if (e->player.step.x < 0)
			ft_set(c, 0, 0, 255);
		else
			ft_set(c, 0, 255, 0);
	}
	else
	{
		if (e->player.step.y < 0)
			ft_set(c, 255, 0, 255);
		else
			ft_set(c, 255, 255, 0);
	}
}
