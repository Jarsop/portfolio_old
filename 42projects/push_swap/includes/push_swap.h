/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 23:46:31 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/29 19:46:22 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "stdlib.h"

# define D     0
# define V     3
# define C     4
# define HO    0
# define SA    1
# define HA    1
# define SB    2
# define HB    2
# define MINA  5
# define MAXA  6
# define MINB  7
# define MAXB  8
# define HMINA 9
# define HMAXA 10
# define HMINB 11
# define HMAXB 12

/*
******************init and check**************************
*/

int		**ft_initps(int ac, char **av);
void	ft_minmaxa(int ***stack);

/*
*****************start and resolve************************
*/

void	ft_ps(int ac, char **av, int v);

/*
***********************operator***************************
*/

void	ft_sa(int **stack, int p);
void	ft_ra(int **stack, int p);
void	ft_rra(int **stack, int p);
void	ft_pa(int **stack);
void	ft_sb(int **stack, int p);
void	ft_rb(int **stack, int p);
void	ft_rrb(int **stack, int p);
void	ft_pb(int **stack);
void	ft_ss(int ***stack);
void	ft_rr(int ***stack);
void	ft_rrr(int ***stack);

/*
************************cores****************************
*/

void	ft_core_pa(int ***stack);
void	ft_core_pb(int ***stack);
void	ft_core_sa(int ***stack);
void	ft_core_sb(int ***stack);
void	ft_core_ss(int ***stack);
void	ft_core_ra(int ***stack);
void	ft_core_rb(int ***stack);
void	ft_core_rr(int ***stack);
void	ft_core_rra(int ***stack);
void	ft_core_rrb(int ***stack);
void	ft_core_rrr(int ***stack);
void	ft_core_preva(int ***stack);
void	ft_core_prevb(int ***stack);

/*
**********************check sort*************************
*/

int		ft_isok(int **stack);
int		ft_isoka(int **stack);
int		ft_isokb(int **stack);

/*
************************bonus****************************
*/

void	ft_printstack(int **stack);

#endif
