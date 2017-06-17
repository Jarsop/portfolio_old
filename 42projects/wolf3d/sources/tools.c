/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:22:57 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 18:37:24 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

double		ft_tex_help(t_w *e, int *texxy)
{
	double	wallx;

	if (!e->player.wallside)
		wallx = e->r.pos.y + e->player.distwall * e->r.dir.y;
	else
		wallx = e->r.pos.x + e->player.distwall * e->r.dir.x;
	wallx -= floor(wallx);
	*texxy = (int)(wallx * (double)BLOC);
	return (wallx);
}

void		ft_tex(t_w *e, int x)
{
	double	wallx;
	int		y[2];
	int		texxy[3];
	size_t	color;
	int		*img;

	img = (int*)e->m.imgc;
	texxy[2] = e->map.map[e->r.posmap.x][e->r.posmap.y] - 1;
	wallx = ft_tex_help(e, &texxy[0]);
	if (!e->player.wallside && e->r.dir.x > 0)
		texxy[0] = BLOC - texxy[0] - 1;
	if (e->player.wallside && e->r.dir.y < 0)
		texxy[0] = BLOC - texxy[0] - 1;
	y[0] = e->r.ystart;
	while (y[0] < e->r.yend)
	{
		y[1] = y[0] * 256 - WIN_Y * 128 + e->r.lheight * 128;
		texxy[1] = ((y[1] * BLOC) / e->r.lheight) / 256;
		color = e->tex[texxy[2]].str[BLOC * texxy[1] + texxy[0]];
		if (e->player.wallside)
			color = (color >> 1) & 8355711;
		img[WIN_X * y[0] + x] = color;
		++y[0];
	}
}

void		ft_drawspace(t_w *e)
{
	int		*img;
	int		x;
	int		y;

	y = -1;
	img = (int*)e->m.imgc;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			img[x + y * WIN_X] = e->space.str[x + y * WIN_X];
	}
}
