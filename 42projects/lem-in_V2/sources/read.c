/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 10:41:13 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/23 19:17:31 by jgeslin          ###   ########.fr       */
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

void	ft_printline(t_hex *h, int n)
{
	if (h && h->name && h->next[n] && h->next[n]->name)
	{
		ft_printf("(\033[1;35m %p \033[0m)->[\033[32m %s \033[0m]--> "
		"lnk[\033[33m %d \033[0m] = [\033[1;34m %s \033[0m]->"
		"(\033[35m %p \033[0m)\n",
		h, h->name, n, h->next[n]->name, h->next[n]);
	}
}

char	*ft_adjust_cont(char *line)
{
	char	*t;
	int		nb;

	nb = 0;
	while (line[nb] && line[nb] != 32)
		++nb;
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
	char	*s;

	t = *rec;
	while (t)
	{
		s = (char*)t->content;
		if (s[0] != 'L' && s[0] != '#')
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
	while (get_next_line(0, &line) > 0 && line[0] && line[0] != 'L' &&
	ft_strascii(line))
	{
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
			++nb;
		ft_lstpushback(&rec, line, ft_strlen(line) + 1);
		free(line);
		line = NULL;
	}
	free(line);
	if (rec)
		ft_all(rec, nb);
	else
		ft_error("ERROR\n");
}
