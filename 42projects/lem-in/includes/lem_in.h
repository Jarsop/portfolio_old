/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:24:27 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/21 22:00:55 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_hex{
	int				n;
	int				se;
	int				nbhex;
	size_t			ants;
	char			*name;
	struct s_hex	*prev;
	struct s_hex	**next;
}					t_hex;

void				ft_readstd(void);
void				ft_lstfree(t_list *rec);
void				ft_inithex(t_list **rec, int ants, int v);
void				ft_printparse(t_list **rec);
void				ft_hexpushback(t_hex **hex, char *str, int node);
void				ft_relink(t_hex **hex, t_list **rec);
int					ft_start(t_hex **hex, t_list **rec);
int					ft_end(t_hex **hex, t_list **rec);
void				ft_freehex(t_hex *hex);
int					ft_ants(t_list **rec);
void				ft_nbrhex(t_hex **hex, t_list **rec);
int					ft_verbose(t_list **res);
void				ft_resolve(t_hex **hex, int ants);
void				ft_printresult(t_list **res, t_hex **hex, int ants);

#endif
