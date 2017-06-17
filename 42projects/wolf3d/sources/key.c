/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 13:57:49 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 18:50:41 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <sys/time.h>

void	ft_get_timeframe(t_w *e)
{
	struct timeval	time;

	e->oldtime = e->time;
	gettimeofday(&time, NULL);
	e->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	e->frametime = e->time - e->oldtime;
	e->player.mspeed = !e->speed ? e->frametime * 0.003 : e->frametime * 0.005;
	e->player.rspeed = !e->speed ? e->frametime * 0.003 : e->frametime * 0.005;
}

int		ft_key_press(int keycode, t_w *e)
{
	if (keycode == 123)
		e->player.move.left = 1;
	if (keycode == 126)
		e->player.move.up = 1;
	if (keycode == 124)
		e->player.move.right = 1;
	if (keycode == 125)
		e->player.move.down = 1;
	if (keycode == 49)
		e->player.sprint = 1;
	return (0);
}

int		ft_key_release(int keycode, t_w *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		e->player.move.left = 0;
	if (keycode == 126)
		e->player.move.up = 0;
	if (keycode == 124)
		e->player.move.right = 0;
	if (keycode == 125)
		e->player.move.down = 0;
	if (keycode == 49)
		e->player.sprint = 0;
	if (keycode == 15)
		ft_init(e);
	if (keycode == 17)
		e->offtex = e->offtex ? 0 : 1;
	if (keycode == 1)
		e->speed = e->speed ? 0 : 1;
	return (0);
}

void	ft_turn(t_w *e, char dir)
{
	double	tmpdir;
	double	tmpplane;
	int		coef;

	coef = 1;
	tmpdir = e->player.dir.x;
	tmpplane = e->r.plane.x;
	if (dir)
		coef = -1;
	e->player.dir.x = e->player.dir.x * cos(coef * e->player.rspeed)
		- e->player.dir.y * sin(coef * e->player.rspeed);
	e->player.dir.y = tmpdir * sin(coef * e->player.rspeed)
		+ e->player.dir.y * cos(coef * e->player.rspeed);
	e->r.plane.x = e->r.plane.x * cos(coef * e->player.rspeed)
		- e->r.plane.y * sin(coef * e->player.rspeed);
	e->r.plane.y = tmpplane * sin(coef * e->player.rspeed)
		+ e->r.plane.y * cos(coef * e->player.rspeed);
}

void	ft_move(t_w *e)
{
	if (e->player.sprint)
		e->player.mspeed *= 2;
	if (e->player.move.up)
	{
		if (!(e->map.map[(int)(e->player.pos.x + e->player.dir.x *
						e->player.mspeed)][(int)(e->player.pos.y)]))
			e->player.pos.x += e->player.dir.x * e->player.mspeed;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y +
						e->player.dir.y * e->player.mspeed)]))
			e->player.pos.y += e->player.dir.y * e->player.mspeed;
	}
	if (e->player.move.left)
		ft_turn(e, 0);
	if (e->player.move.right)
		ft_turn(e, 1);
	if (e->player.move.down)
	{
		if (!(e->map.map[(int)(e->player.pos.x - e->player.dir.x
						* e->player.mspeed)][(int)(e->player.pos.y)]))
			e->player.pos.x -= e->player.dir.x * e->player.mspeed;
		if (!(e->map.map[(int)(e->player.pos.x)][(int)(e->player.pos.y
						- e->player.dir.y * e->player.mspeed)]))
			e->player.pos.y -= e->player.dir.y * e->player.mspeed;
	}
}
