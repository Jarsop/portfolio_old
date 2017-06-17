/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:54:28 by jgeslin           #+#    #+#             */
/*   Updated: 2016/02/21 21:32:39 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

void	ft_init_tab7(t_conv *conv)
{
	conv[48].conv = "r";
	conv[48].mask = MASK_R;
	conv[48].p = ft_function_wild;
	conv[49].conv = "k";
	conv[49].mask = MASK_K;
	conv[49].p = ft_function_wild;
	conv[51].conv = "-";
	conv[51].mask = MASK_NEG;
	conv[51].p = ft_function_fneg;
	conv[50].conv = "%";
	conv[50].mask = MASK_NOT;
	conv[50].p = ft_function_pc;
}

void	ft_init_tab6(t_conv *conv)
{
	conv[40].conv = "f";
	conv[40].mask = MASK_F;
	conv[40].p = ft_function_wild;
	conv[41].conv = "F";
	conv[41].mask = MASK_FF;
	conv[41].p = ft_function_wild;
	conv[42].conv = "g";
	conv[42].mask = MASK_G;
	conv[42].p = ft_function_wild;
	conv[43].conv = "G";
	conv[43].mask = MASK_GG;
	conv[43].p = ft_function_wild;
	conv[44].conv = "a";
	conv[44].mask = MASK_A;
	conv[44].p = ft_function_wild;
	conv[45].conv = "A";
	conv[45].mask = MASK_AA;
	conv[45].p = ft_function_wild;
	conv[46].conv = "n";
	conv[46].mask = MASK_N;
	conv[46].p = ft_function_wild;
	conv[47].conv = "b";
	conv[47].mask = MASK_B;
	conv[47].p = ft_function_wild;
}

void	ft_init_tab5(t_conv *conv)
{
	conv[32].conv = "U";
	conv[32].mask = MASK_UU;
	conv[32].p = ft_function_uu;
	conv[33].conv = "x";
	conv[33].mask = MASK_X;
	conv[33].p = ft_function_x;
	conv[34].conv = "X";
	conv[34].mask = MASK_XX;
	conv[34].p = ft_function_xx;
	conv[35].conv = "p";
	conv[35].mask = MASK_P;
	conv[35].p = ft_function_p;
	conv[36].conv = "o";
	conv[36].mask = MASK_O;
	conv[36].p = ft_function_o;
	conv[37].conv = "O";
	conv[37].mask = MASK_OO;
	conv[37].p = ft_function_oo;
	conv[38].conv = "e";
	conv[38].mask = MASK_E;
	conv[38].p = ft_function_wild;
	conv[39].conv = "E";
	conv[39].mask = MASK_EE;
	conv[39].p = ft_function_wild;
}
