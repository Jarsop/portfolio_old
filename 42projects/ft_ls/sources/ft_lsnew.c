/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 14:46:07 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/24 22:15:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <stdlib.h>

t_ls	*ft_lsnew(char const *name, char *realname)
{
	t_ls	*new;

	if (!(new = (t_ls*)ft_memalloc(sizeof(t_ls))))
		return (NULL);
	new->next = NULL;
	if (!(new->stat = (t_stat*)ft_memalloc(sizeof(t_stat))))
		return (NULL);
	new->group = NULL;
	new->passwd = NULL;
	if (!(new->name = ft_strdup(name)))
		return (NULL);
	if (!(new->realname = ft_strdup(realname)))
		return (NULL);
	new->pname = NULL;
	new->gname = NULL;
	new->mtime = NULL;
	return (new);
}
