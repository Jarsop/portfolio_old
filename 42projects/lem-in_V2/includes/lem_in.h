/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:24:27 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 16:59:20 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
***********************************Lem-in**************************************
*/

# include <stdlib.h>
# include "../libft/includes/libft.h"

/*
*******************************Struct List Tab*********************************
*/

typedef struct		s_best{
	int				n;
	t_list			**lst;
}					t_best;

/*
***********************************Struct Hex**********************************
*/

typedef struct		s_hex{
	int				n;
	int				se;
	int				nbhex;
	size_t			ants;
	char			*name;
	struct s_hex	*prev;
	struct s_hex	**next;
}					t_hex;

/*
************************************Parsing************************************
*/

void				ft_readstd(void);
void				ft_all(t_list *rec, int nb);
void				ft_adjust(t_list **rec);

/*
*************************************List**************************************
*/

void				ft_lstfree(t_list *rec);

/*
*************************************Hex***************************************
*/

void				ft_inithex(t_list **rec, int ants, int v);
void				ft_hexpushback(t_hex **hex, char *str, int node);
void				ft_relink(t_hex **hex, t_list **rec);
int					ft_start(t_hex **hex, t_list **rec);
int					ft_end(t_hex **hex, t_list **rec);
void				ft_freehex(t_hex *hex);
int					ft_ants(t_list **rec);
void				ft_nbrhex(t_hex **hex, t_list **rec);
int					ft_hexok(t_hex **hex);

/*
************************************Solve**************************************
*/

void				ft_resolve(t_hex **hex, int ants);
t_list				*ft_findbest(t_list	**res, t_hex *hex);
int					ft_bnotinlist(char *name, t_list **res);
int					ft_bestok(t_best *best);

/*
************************************Print**************************************
*/

void				ft_printresult(t_list **res, t_hex **hex, int ants);
void				ft_printparse(t_list **rec);
void				ft_printline(t_hex *h, int n);

/*
************************************Bonus**************************************
*/

int					ft_verbose(t_list **res);

#endif
