/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:40:55 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/17 22:13:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <pthread.h>

# define WIN_X 800
# define WIN_Y 600
# define WIN_X3 WIN_X / 3
# define WIN_Y3 WIN_Y / 3
# define NB_THREADS 8
# define NB_THREADS_K 3
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define ABS(a) (((a) < 0) ? -(a) : (a))
# define SQRT_3  1.732
# define X1 0
# define Y1 1
# define X2 2
# define Y2 3

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*imgc;
	int				index;
	int				bpp;
	int				sl;
	int				e;
	int				b;
	double			zoom;
	double			x_o;
	double			y_o;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			tmpx;
	double			tmpx2;
	double			tmpy;
	double			tmpy2;
	double			im_x;
	double			im_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int				i;
	int				t;
	int				c;
	size_t			tx;
	size_t			ty;
	double			x;
	double			y;
	size_t			iteration_max;
}					t_mlx;

typedef struct		s_th
{
	pthread_t		th;
	double			x1;
	double			y1;
	double			x_o;
	double			y_o;
	double			zoom;
	double			c_r;
	double			c_i;
	int				*cp;
	int				c_th;
	int				x;
	int				y;
	int				i;
	int				i_max;
	int				c;
}					t_th;

/*
***********************************Init****************************************
*/

void				ft_init_mandelbrot(t_mlx *mlx);
void				ft_init_julia(t_mlx *mlx);
void				ft_init_mandelbrot1(t_mlx *mlx);
void				ft_init_bship(t_mlx *mlx);
void				ft_init_mlxk(t_mlx *mlx);
void				ft_init_mlxk(t_mlx *mlx);
void				ft_init_tk(int **t, int *k);
int					*ft_init_tkm(t_mlx *mlx, int *koch);
void				ft_init_koch(t_mlx *mlx, int o);

/*
**********************************Fractals*************************************
*/
void				ft_mandelbrot(void);
void				ft_mandelbrot_t(void);
void				ft_mandelbrot1(void);
void				ft_julia(void);
void				ft_julia_t(void);
void				ft_bship(void);
void				ft_koch(void);
void				ft_fougere(void);

/*
***********************************Tools***************************************
*/

int					ft_julia_hook(int x, int y, t_mlx *mlx);
void				ft_rotjulia(t_mlx *mlx);

/*
************************************Key****************************************
*/

int					ft_key_mandelbrot(int keyhook, t_mlx *mlx);
int					ft_key_julia(int keyhook, t_mlx *mlx);
int					ft_key_koch(int keyhook, t_mlx *mlx);
int					ft_mouse_hook(int keycode, int x, int y, t_mlx *mlx);

#endif
