/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:06:21 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:55:11 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void	ft_init_tab4(t_conv *conv)
{
	conv[24].conv = "c";
	conv[24].mask = MASK_C;
	conv[24].p = ft_function_c;
	conv[25].conv = "C";
	conv[25].mask = MASK_CC;
	conv[25].p = ft_getwchart;
	conv[26].conv = "d";
	conv[26].mask = MASK_D;
	conv[26].p = ft_function_d;
	conv[27].conv = "D";
	conv[27].mask = MASK_DD;
	conv[27].p = ft_function_dd;
	conv[28].conv = "s";
	conv[28].mask = MASK_S;
	conv[28].p = ft_function_s;
	conv[29].conv = "S";
	conv[29].mask = MASK_SS;
	conv[29].p = ft_getwstringt;
	conv[30].conv = "i";
	conv[30].mask = MASK_I;
	conv[30].p = ft_function_d;
	conv[31].conv = "u";
	conv[31].mask = MASK_U;
	conv[31].p = ft_function_u;
}

static void	ft_init_tab3(t_conv *conv)
{
	conv[16].conv = "9";
	conv[16].mask = MASK_DIG9;
	conv[16].p = ft_function_digit;
	conv[17].conv = "0";
	conv[17].mask = MASK_ZERO;
	conv[17].p = ft_function_0;
	conv[18].conv = "j";
	conv[18].mask = MASK_J;
	conv[18].p = ft_function_j;
	conv[19].conv = "z";
	conv[19].mask = MASK_Z;
	conv[19].p = ft_function_z;
	conv[20].conv = "ll";
	conv[20].mask = MASK_LL;
	conv[20].p = ft_function_ll;
	conv[21].conv = "l";
	conv[21].mask = MASK_L;
	conv[21].p = ft_function_l;
	conv[22].conv = "hh";
	conv[22].mask = MASK_HH;
	conv[22].p = ft_function_hh;
	conv[23].conv = "h";
	conv[23].mask = MASK_H;
	conv[23].p = ft_function_h;
}

static void	ft_init_tab2(t_conv *conv)
{
	conv[8].conv = "1";
	conv[8].mask = MASK_DIG1;
	conv[8].p = ft_function_digit;
	conv[9].conv = "2";
	conv[9].mask = MASK_DIG2;
	conv[9].p = ft_function_digit;
	conv[10].conv = "3";
	conv[10].mask = MASK_DIG3;
	conv[10].p = ft_function_digit;
	conv[11].conv = "4";
	conv[11].mask = MASK_DIG4;
	conv[11].p = ft_function_digit;
	conv[12].conv = "5";
	conv[12].mask = MASK_DIG5;
	conv[12].p = ft_function_digit;
	conv[13].conv = "6";
	conv[13].mask = MASK_DIG6;
	conv[13].p = ft_function_digit;
	conv[14].conv = "7";
	conv[14].mask = MASK_DIG7;
	conv[14].p = ft_function_digit;
	conv[15].conv = "8";
	conv[15].mask = MASK_DIG8;
	conv[15].p = ft_function_digit;
}

static void	ft_init_tab1(t_conv *conv)
{
	conv[0].conv = "#";
	conv[0].mask = MASK_HASH;
	conv[0].p = ft_function_hashtag;
	conv[1].conv = "+";
	conv[1].mask = MASK_POS;
	conv[1].p = ft_function_fpos;
	conv[2].conv = " ";
	conv[2].mask = MASK_SPACE;
	conv[2].p = ft_function_fspace;
	conv[3].conv = "*";
	conv[3].mask = MASK_WILD;
	conv[3].p = ft_function_wild;
	conv[4].conv = "$";
	conv[4].mask = MASK_DOL;
	conv[4].p = ft_function_a;
	conv[5].conv = ".";
	conv[5].mask = MASK_POINT;
	conv[5].p = ft_function_point;
	conv[6].conv = "$";
	conv[6].mask = MASK_DOL;
	conv[6].p = ft_function_a;
	conv[7].conv = "'";
	conv[7].mask = MASK_AP;
	conv[7].p = ft_function_a;
}

void		ft_init_tab(t_conv *conv)
{
	ft_init_tab1(conv);
	ft_init_tab2(conv);
	ft_init_tab3(conv);
	ft_init_tab4(conv);
	ft_init_tab5(conv);
	ft_init_tab6(conv);
	ft_init_tab7(conv);
}
