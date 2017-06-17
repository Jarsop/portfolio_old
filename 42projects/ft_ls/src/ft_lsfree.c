/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 16:38:26 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/24 22:16:18 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>

void	ft_lsfree(t_ls *ls)
{
	if (ls->next)
		ft_lsfree(ls->next);
	if (ls->name)
		free(ls->name);
	if (ls->realname)
		free(ls->realname);
	if (ls->stat)
		free(ls->stat);
	if (ls->right)
		free(ls->right);
	if (ls->serrno)
		free(ls->serrno);
	if (ls->mtime)
		free(ls->mtime);
	if (ls->pname)
		free(ls->pname);
	if (ls->gname)
		free(ls->gname);
	free(ls);
	ls = NULL;
}
