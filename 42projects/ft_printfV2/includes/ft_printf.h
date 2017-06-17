/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:20:01 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/19 19:20:50 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include "../libft/includes/libft.h"

# define TAB_LEN		52
# define LEN_CONV_MIN	24
# define LEN_CONV_MAX	50
# define LEN_FLAG_MIN	0
# define LEN_FLAG_MAX	24

# define MASK_NULL	0x0000000000000000
# define MASK_HASH	0x0000000000000001
# define MASK_NEG	0x0000000000000002
# define MASK_POS	0x0000000000000004
# define MASK_SPACE	0x0000000000000008
# define MASK_WILD	0x0000000000000010
# define MASK_DOL	0x0000000000000020
# define MASK_POINT	0x0000000000000040
# define MASK_AP	0x0000000000000080
# define MASK_DIG1	0x0000000000000100
# define MASK_DIG2	0x0000000000000100
# define MASK_DIG3	0x0000000000000100
# define MASK_DIG4	0x0000000000000100
# define MASK_DIG5	0x0000000000000100
# define MASK_DIG6	0x0000000000000100
# define MASK_DIG7	0x0000000000000100
# define MASK_DIG8	0x0000000000000100
# define MASK_DIG9	0x0000000000000100
# define MASK_ZERO	0x0000000000000200
# define MASK_J		0x0000000000000400
# define MASK_Z		0x0000000000000800
# define MASK_LL	0x0000000000001000
# define MASK_L		0x0000000000002000
# define MASK_HH	0x0000000000004000
# define MASK_H		0x0000000000008000
# define MASK_C		0x0000000000010000
# define MASK_CC	0x0000000000020000
# define MASK_D		0x0000000000040000
# define MASK_DD	0x0000000000080000
# define MASK_S		0x0000000000100000
# define MASK_SS	0x0000000000200000
# define MASK_I		0x0000000000400000
# define MASK_U		0x0000000000800000
# define MASK_UU	0x0000000001000000
# define MASK_X		0x0000000002000000
# define MASK_XX	0x0000000004000000
# define MASK_P		0x0000000008000000
# define MASK_O		0x0000000010000000
# define MASK_OO	0x0000000020000000
# define MASK_E		0x0000000040000000
# define MASK_EE	0x0000000080000000
# define MASK_F		0x0000000100000000
# define MASK_FF	0x0000000200000000
# define MASK_G		0x0000000400000000
# define MASK_GG	0x0000000800000000
# define MASK_A		0x0000001000000000
# define MASK_AA	0x0000002000000000
# define MASK_N		0x0000004000000000
# define MASK_B		0x0000008000000000
# define MASK_R		0x0000010000000000
# define MASK_K		0x0000020000000000
# define MASK_NOT	0x0000040000000000

typedef struct	s_conv
{
	char			*conv;
	unsigned long	mask;
	char			*(*p)(const char *, va_list);
}				t_conv;

va_list			g_cpy;
unsigned long	g_mask;
unsigned int	g_wc1;
unsigned int	g_wc2;
unsigned int	g_wc3;
char			*g_f;
int				g_point;
int				g_n;
int				g_len;
int				g_p;
int				g_l;
char			*g_str;
char			*g_z;
int				g_i;
char			*g_save;
int				ft_printf(const char *format, ...);
char			*ft_wformat(va_list ap, const char *format, t_conv *t_mask);
int				ft_strconv(char *ftmp);
void			ft_patch(void);
void			ft_pstr(char *ftmp);
/*
**				UNICODE FUNCTIONS
*/
char			*ft_getwstringt(const char *format, va_list ap);
char			*ft_getwschart(unsigned int wc);
char			*ft_getwchart(const char *format, va_list ap);
/*
**				HELP FUNCTIONS
*/
void			ft_optimask(char *ftmp);
char			*ft_help_h(va_list ap);
char			*ft_help_hh(va_list ap);
char			*ft_help_l(va_list ap, const char *format);
char			*ft_help_ll(va_list ap);
void			ft_help_point(char **str, int *i);
char			*ft_help_point2(void);
void			ft_help_0(char **str, int *i);
void			ft_help_digit(char **str, int *i);
void			ft_help_job(va_list ap, char **ftmp, t_conv *t_mask, int i);
unsigned long	ft_help_pop(t_conv *t_mask, char **tmp);
/*
**				INIT FUNCTIONS
*/
void			ft_init_tab(t_conv *conv);
void			ft_init_tab5(t_conv *conv);
void			ft_init_tab6(t_conv *conv);
void			ft_init_tab7(t_conv *conv);
/*
**				CONVERSION FUNCTIONS
*/
char			*ft_function_hashtag(const char *format, va_list ap);
char			*ft_function_point(const char *format, va_list ap);
char			*ft_function_fspace(const char *format, va_list ap);
char			*ft_function_fpos(const char *format, va_list ap);
char			*ft_function_fneg(const char *format, va_list ap);
char			*ft_function_h(const char *format, va_list ap);
char			*ft_function_hh(const char *format, va_list ap);
char			*ft_function_l(const char *format, va_list ap);
char			*ft_function_ll(const char *format, va_list ap);
char			*ft_function_j(const char *format, va_list ap);
char			*ft_function_z(const char *format, va_list ap);
char			*ft_function_0(const char *format, va_list ap);
char			*ft_function_digit(const char *format, va_list ap);
char			*ft_function_d(const char *format, va_list ap);
char			*ft_function_dd(const char *format, va_list ap);
char			*ft_function_s(const char *format, va_list ap);
char			*ft_function_c(const char *format, va_list ap);
char			*ft_function_o(const char *format, va_list ap);
char			*ft_function_oo(const char *format, va_list ap);
char			*ft_function_x(const char *format, va_list ap);
char			*ft_function_xx(const char *format, va_list ap);
char			*ft_function_u(const char *format, va_list ap);
char			*ft_function_uu(const char *format, va_list ap);
char			*ft_function_p(const char *format, va_list ap);
char			*ft_function_a(const char *format, va_list ap);
char			*ft_function_pc(const char *format, va_list ap);
char			*ft_function_wild(const char *format, va_list ap);

#endif
