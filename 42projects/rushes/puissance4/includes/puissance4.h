/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puissance4.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 09:32:13 by gvilmont          #+#    #+#             */
/*   Updated: 2016/02/28 07:59:43 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUISSANCE4_H
# define PUISSANCE4_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define RED "\033[0;31m"
# define DEF "\033[0;m"
# define ER_H RED "Enter a valid number, min 6 and max int_MAX for length\n" DEF
# define ER_W RED "Enter a valid number, min 7 and max int_MAX for weigth\n" DEF
# define ER_ARG RED "Need two arguments, no more no less\n" DEF

long	g_le;
long	g_h;
int		g_maxi;
int		g_maxj;
int		g_sj1;
int		g_sj2;
char	**ft_initmap(void);
void	ft_printtab(char **tab);
char	**ft_filltab(char **tab);
int		ft_win(char **tab);
void	ft_nb_series3(char **jeu, int *series_j1, int *series_j2);
void	ft_nb_series4(char **jeu, int *series_j1, int *series_j2);
int		ft_eval(char **jeu);
int		ft_winner(char **jeu);
int		ft_min(char **jeu, int profondeur);
int		ft_max(char **jeu, int profondeur);
void	ft_iaturn(char **jeu, int profondeur);
void	ft_checklinev(char **jeu, int *sj1, int *sj2, int n);
void	ft_checklineh(char **jeu, int *sj1, int *sj2, int n);
void	ft_checkdiagdown3(char **tab, int *sj1, int *sj2);
void	ft_checkdiagdown4(char **tab, int *sj1, int *sj2);
void	ft_checkdiagup3(char **tab, int *sj1, int *sj2);
void	ft_checkdiagup4(char **tab, int *sj1, int *sj2);
void	ft_checklineh3(char **tab, int *sj1, int *sj2);
void	ft_checklineh4(char **tab, int *sj1, int *sj2);
void	ft_checklinev3(char **tab, int *sj1, int *sj2);
void	ft_checklinev4(char **tab, int *sj1, int *sj2);

#endif
