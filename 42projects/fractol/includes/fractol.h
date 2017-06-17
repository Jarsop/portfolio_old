/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:40:55 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/31 15:15:08 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>

# define WIN_X 800
# define WIN_Y 600

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*imgc;
	int			index;
	int			bpp;
	int			sl;
	int			e;
	int			b;
	double		x_o;
	double		y_o;
	double		zoom;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		tmpx;
	double		tmpx2;
	double		tmpy;
	double		tmpy2;
	double		im_x;
	double		im_y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	size_t		iteration_max;
}				t_mlx;

/*
***********************************Init****************************************
*/

void			ft_init_mandelbrot(t_mlx *mlx);
void			ft_init_julia(t_mlx *mlx);
void			ft_init_buddahbrot(t_mlx *mlx);
void			ft_init_mandelbrot1(t_mlx *mlx);
void			ft_init_bship(t_mlx *mlx);

/*
**********************************Fractals*************************************
*/
void			ft_mandelbrot(void);
void			ft_mandelbrot1(void);
void			ft_julia(void);
void			ft_buddahbrot(void);
void			ft_bship(void);

/*
***********************************Tools***************************************
*/

/*
************************************Key****************************************
*/

int				ft_key_mandelbrot(int keyhook, t_mlx *mlx);
int				ft_key_julia(int keyhook, t_mlx *mlx);
int				ft_mouse_hook(int keycode, int x, int y, t_mlx *mlx);

#endif
