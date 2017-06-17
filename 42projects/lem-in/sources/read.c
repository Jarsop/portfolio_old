/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:41:13 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/21 21:52:25 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_lstfree(t_list *rec)
{
	if (rec->next)
		ft_lstfree(rec->next);
	if (rec->content)
		free(rec->content);
	if (rec)
		free(rec);
}

char	*ft_adjust_cont(char *line)
{
	char	*t;
	int		nb;

	nb = ft_strlen(line);
	while (nb && line[nb] != 32)
		--nb;
	while (nb && line[nb] != 32)
		--nb;
	nb -= 2;
	if (nb > 0)
	{
		t = line;
		line = ft_strsub(line, 0, nb);
		free(t);
	}
	return (line);
}

void	ft_adjust(t_list **rec)
{
	t_list	*t;

	t = *rec;
	while (t)
	{
		t->content = ft_adjust_cont(((char*)(t->content)));
		t->content_size = 0;
		t = t->next;
	}
}

void	ft_readstd(void)
{
	t_list	*rec;
	char	*line;
	int		nb;

	nb = 0;
	rec = NULL;
	line = NULL;
	while (get_next_line(0, &line) > 0 && line[0] && line[0] != 'L')
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			++nb;
		ft_lstpushback(&rec, line, ft_strlen(line) + 1);
		free(line);
	}
	if (rec)
	{
		ft_printparse(&rec);
		ft_adjust(&rec);
		if (nb == 2)
			ft_inithex(&rec, ft_ants(&rec), ft_verbose(&rec));
		else
			ft_error("ERROR\n");
		ft_lstfree(rec);
	}
}
