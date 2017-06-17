/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 23:54:19 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 18:22:41 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void	ft_init(t_w *env)
{
	env->offtex = 0;
	env->speed = 0;
	env->player.move.up = 0;
	env->player.move.down = 0;
	env->player.sprint = 0;
	env->player.pos.x = 20;
	env->player.pos.y = 20;
	env->player.dir.x = -1;
	env->player.dir.y = 0;
	env->r.plane.x = 0;
	env->r.plane.y = 0.66;
	env->time = 0;
	env->oldtime = 0;
}

void	ft_inittex_bis(t_w *e)
{
	e->tex[4].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/mossy.xpm",
					&e->tex[4].sl, &e->tex[4].e);
	e->tex[4].str = (int*)mlx_get_data_addr(e->tex[4].img, &e->tex[4].bpp,
					&e->tex[4].sl, &e->tex[4].e);
	e->tex[5].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/pillar.xpm",
					&e->tex[5].sl, &e->tex[5].e);
	e->tex[5].str = (int*)mlx_get_data_addr(e->tex[5].img, &e->tex[5].bpp,
					&e->tex[5].sl, &e->tex[5].e);
	e->tex[6].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/purplestone.xpm",
					&e->tex[6].sl, &e->tex[6].e);
	e->tex[6].str = (int*)mlx_get_data_addr(e->tex[6].img, &e->tex[6].bpp,
					&e->tex[6].sl, &e->tex[6].e);
	e->tex[7].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/redbrick.xpm",
					&e->tex[7].sl, &e->tex[7].e);
	e->tex[7].str = (int*)mlx_get_data_addr(e->tex[7].img, &e->tex[7].bpp,
					&e->tex[7].sl, &e->tex[7].e);
	e->tex[8].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/wood.xpm",
					&e->tex[8].sl, &e->tex[8].e);
	e->tex[8].str = (int*)mlx_get_data_addr(e->tex[8].img, &e->tex[8].bpp,
					&e->tex[8].sl, &e->tex[8].e);
}

void	ft_inittex(t_w *e)
{
	e->tex[0].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/bluestone.xpm",
					&e->tex[0].sl, &e->tex[0].e);
	e->tex[0].str = (int*)mlx_get_data_addr(e->tex[0].img, &e->tex[0].bpp,
					&e->tex[0].sl, &e->tex[0].e);
	e->tex[1].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/colorstone.xpm",
					&e->tex[1].sl, &e->tex[1].e);
	e->tex[1].str = (int*)mlx_get_data_addr(e->tex[1].img, &e->tex[1].bpp,
					&e->tex[1].sl, &e->tex[1].e);
	e->tex[2].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/eagle.xpm",
					&e->tex[2].sl, &e->tex[2].e);
	e->tex[2].str = (int*)mlx_get_data_addr(e->tex[2].img, &e->tex[2].bpp,
					&e->tex[2].sl, &e->tex[2].e);
	e->tex[3].img = mlx_xpm_file_to_image(e->m.mlx, "./pics/greystone.xpm",
					&e->tex[3].sl, &e->tex[3].e);
	e->tex[3].str = (int*)mlx_get_data_addr(e->tex[3].img, &e->tex[3].bpp,
					&e->tex[3].sl, &e->tex[3].e);
	ft_inittex_bis(e);
}

void	ft_initspace(t_w *e)
{
	e->space.img = mlx_xpm_file_to_image(e->m.mlx, "./pics/space.xpm",
					&e->space.sl, &e->space.e);
	e->space.str = (int*)mlx_get_data_addr(e->space.img, &e->space.bpp,
					&e->space.sl, &e->space.e);
}

void	ft_start_game(t_w *e)
{
	e->m.mlx = mlx_init();
	e->m.win = mlx_new_window(e->m.mlx, WIN_X, WIN_Y, "Wolf 3D");
	e->m.img = NULL;
	e->m.img = mlx_new_image(e->m.mlx, WIN_X, WIN_Y);
	e->m.imgc = mlx_get_data_addr(e->m.img, &(e->m.bpp), &(e->m.sl), &(e->m.e));
	ft_inittex(e);
	ft_initspace(e);
	ft_init(e);
	mlx_hook(e->m.win, 2, (1L << 0), ft_key_press, e);
	mlx_hook(e->m.win, 3, (1L << 1), ft_key_release, e);
	mlx_hook(e->m.win, 17, (1L << 17), &ft_quit, e);
	mlx_hook(e->m.win, 6, (1L << 6), ft_mouse, e);
	mlx_loop_hook(e->m.mlx, ft_loop_hook, e);
	mlx_loop(e->m.mlx);
}
