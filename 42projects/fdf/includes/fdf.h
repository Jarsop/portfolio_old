/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:46:24 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/01 13:40:31 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define WIN_X 1330
# define WIN_Y 780

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xCC0000
# define DARK_BLUE   0x000033
# define D_BLUE      0x000066
# define KING_BLUE   0x000099
# define LIGHT_BLUE  0x0000FF
# define DARK_GREEN  0x003300
# define D_GREEN     0x006600
# define KING_GREEN  0x009900
# define LIGHT_GREEN 0x00FF00
# define DARK_BROWN  0x663300
# define BROWN       0x996600
# define SKIN        0xFFCC99
# define GREY        0xCCCCCC
# define DARK_GREY   0x808080


typedef struct	s_map
{
	int			y;
	int			x;
	int			z;
	int			color;
}				t_map;

typedef struct	s_mlx
{
	t_map		**map;
	void		*mlx;
	void		*win;
	void		*img;
	int			*imgc;
	int			index;
	int			bpp;
	int			sl;
	int			e;

	int			dx;
	int			dy;
	int			x_max;
	int			y_max;
	float		x_o;
	float		y_o;
	float		x_c;
	float		y_c;
	int			pz;
	int			z;
	int			color;
	int			x_p;
	int			y_p;
	int			x_n;
	int			y_n;
	int			x_np;
	int			y_np;
	int			x_t;
	int			y_t;
	int			err;
	int			e2;
	int			sx;
	int			sy;

	int			zoom;
	int			b;
	int			m;
	int			j;
}				t_mlx;

t_map			**ft_parse(char *av, int *xy);
void			ft_mlx(t_map **map, char *av);
void			ft_freemap(t_mlx *mlx);
void			ft_initmlx(t_mlx *mlx);
void			ft_draw(int x, int y, t_mlx *mlx, int c);
int				ft_loop(t_mlx *mlx);
void			ft_print_point(t_mlx *mlx, int y, int x);
void			ft_print_color(int x, int y, t_mlx *mlx, int c);
void			ft_to_do(t_mlx *mlx, int x, int y, int color);
void			ft_print(t_mlx *mlx);
char			*ft_hex(char *line);
void			ft_puterror(int error);
int				ft_open(char *av);

#endif
