/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 21:24:44 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:42:40 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	ft_def(t_ls *t)
{
	char	c;

	c = '\0';
	c = t->right[0] == 'l' ? '@' : c;
	c = t->right[0] == 'd' ? '/' : c;
	c = t->right[0] == '-' && (t->right[3] == 'x' || t->right[6] == 'x'
			|| t->right[9] == 'x') ? '*' : c;
	c = t->right[0] == 'p' ? '|' : c;
	return (c);
}

void	ft_help0(t_ls *t, char *p, char *c, int m)
{
	if (t->right[9] == 't' || t->right[9] == 'T')
		ft_printf("\033[30;42m%s\033[0m%s%s",
			t->realname, m ? c : "\0", p);
	else
		ft_printf("\033[30;43m%s\033[0m%s%s",
			t->realname, m ? c : "\0", p);
}
