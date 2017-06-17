/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:58:27 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/14 11:40:57 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include <libft.h>
# include <stdlib.h>
# include <math.h>

# define WIN_X 1280
# define WIN_Y 720
# define BLOC  64

typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;
typedef struct s_w		t_w;
typedef struct s_c		t_c;
typedef struct s_ci		t_ci;
typedef struct s_map	t_map;
typedef struct s_rgb	t_rgb;
typedef struct s_m		t_m;
typedef struct s_r		t_r;
typedef struct s_p		t_p;

struct					s_c
{
	double	x;
	double	y;
};

struct					s_rgb
{
	int		r;
	int		g;
	int		b;
};

struct					s_ci
{
	int		x;
	int		y;
};

struct					s_m
{
	int		up;
	int		left;
	int		right;
	int		down;
};

struct					s_r
{
	t_c		pos;
	t_c		dir;
	t_c		plane;
	t_c		sidedist;
	t_c		disd;
	t_ci	posmap;
	int		lheight;
	int		ystart;
	int		yend;
};

struct					s_p
{
	t_c		pos;
	t_c		dir;
	t_ci	step;
	t_m		move;
	double	rspeed;
	double	mspeed;
	double	hcamera;
	double	distwall;
	int		hit;
	int		wallside;
	int		sprint;
};

struct					s_map
{
	int		**map;
	int		display;
	int		h;
	int		w;
};

struct					s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgc;
	int		index;
	int		bpp;
	int		sl;
	int		e;
};

struct					s_img
{
	void			*img;
	int				*str;
	int				bpp;
	int				sl;
	int				e;
	int				i;
};

struct					s_w
{
	t_mlx	m;
	t_img	tex[9];
	t_img	space;
	t_img	sol;
	t_p		player;
	t_map	map;
	t_r		r;
	long	frametime;
	double	time;
	double	oldtime;
	int		offtex;
	int		speed;
};

void					ft_map(t_w *env, char *name);
void					ft_tex(t_w *e, int x);
char					**ft_openmap(char *name);
void					ft_drawspace(t_w *e);
int						ft_checkmap(t_w *env, char **map);
void					ft_init(t_w *env);
int						ft_mouse(int x, int y, t_w *e);
int						ft_quit(t_w *e);
void					ft_start_game(t_w *env);
void					ft_get_timeframe(t_w *e);
int						ft_expose_hook(t_w *t);
int						ft_loop_hook(t_w *e);
int						ft_key_release(int keycode, t_w *e);
int						ft_key_press(int keycode, t_w *e);
void					ft_move(t_w *e);
void					ft_colors(t_w *e, t_rgb *c);
void					ft_drawline(int x, t_w *e, t_rgb *c);
void					ft_turn(t_w *e, char dir);

#endif
