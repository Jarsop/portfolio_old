/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 01:48:20 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/19 15:04:29 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

static t_list	*ft_fd(t_list **begin, int fd)
{
	t_list	*tmp;

	tmp = *begin;
	if (tmp)
	{
		while (tmp)
		{
			if ((int)tmp->content_size == fd)
				return (tmp);
			tmp = tmp->next;
		}
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(begin, tmp);
	return (tmp);
}

static char		*ft_line(t_list *current, char *line)
{
	int		n;
	char	*s;

	if (!current->content)
		return (NULL);
	if (ft_strchr(current->content, '\n') != 0)
		n = ft_strlen(current->content) -
			ft_strlen(ft_strchr(current->content, '\n'));
	else
		n = ft_strlen(current->content);
	s = ft_strndup(current->content, n);
	line = ft_strdup(s);
	free(s);
	s = NULL;
	return (line);
}

static char		*ft_current(char *current, char *buf, int ret, int f)
{
	char	*tmp;

	tmp = NULL;
	if (!f)
		current = ft_strwnjoin(current, buf, ret, 0);
	else
	{
		while (*current && *current != '\n')
			++current;
		++current;
	}
	return (current);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*current = NULL;
	t_list			*begin;
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*d;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	begin = current;
	current = ft_fd(&begin, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && !(ft_strchr(buf, '\n')))
		current->content = ft_current((current->content), buf, ret, 0);
	current->content = ft_current((current->content), buf, ret, 0);
	*line = ft_line(current, *line);
	if (!*(char*)(current->content) && (current = begin))
		return (0);
	d = current->content;
	current->content = ft_strdup(ft_current((current->content), buf, ret, 1));
	free(d);
	current = begin;
	return (1);
}
