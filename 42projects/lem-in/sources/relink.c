/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 18:51:31 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/22 01:53:25 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		*ft_find_relink(char *son, char *ori)
{
	char	*s;
	int		i;
	int		i2;

	s = ft_strnstr(son, ori, ft_strlen(ori));
	if (!s)
	{
		s = son + (ft_strlen(son) - ft_strlen(ori));
		s = s[0] == '-' ? s + 1 : s;
	}
	if (son == s)
	{
		i = ft_strlen(ori);
		i2 = ft_strlen(&son[i + 1]);
		return (ft_strdup(&son[son[i + 1] == '-' && i < 2 && i2 < 2 ?
		i : i + 1]));
	}
	else
	{
		i = ori[0] == '-' ? s - son : s - son - 1;
		return (ft_strsub(son, 0, i));
	}
}

void		ft_relinkhex(t_hex **hex, char *ori, char *son)
{
	t_hex	*h;
	t_hex	*h2;
	char	*s;
	int		n;

	h = *hex;
	h2 = *hex;
	n = 0;
	while (h && ft_strcmp(h->name, ori))
		h = h->prev;
	s = ft_find_relink(son, ori);
	if (!s || s[0] == 'L' || s[0] == '#')
		return ;
	while (h2 && ft_strcmp(h2->name, s))
		h2 = h2->prev;
	free(s);
	while (h2 && n < h->n)
	{
		if (!(h->next[n]))
		{
			h->next[n] = h2;
			break ;
		}
		n++;
	}
}

void		ft_check_relink(t_list *t, t_list **rec, t_hex **hex)
{
	t_list	*t2;
	int		c;
	int		n;

	t2 = *rec;
	while (t2)
	{
		n = ft_strlen(t->content);
		if (ft_strlen(t2->content) > n + 1 &&
			((ft_strnstr(t2->content, t->content, n) ||
			ft_strnrstr(t2->content, t->content, n))) &&
		(((char*)t2->content)[n] == '-' ||
		((char*)t2->content)[ft_strlen(t2->content) - n - 1] == '-'))
			ft_relinkhex(hex, t->content, t2->content);
		t2 = t2->next;
	}
}

void		ft_relink(t_hex **hex, t_list **rec)
{
	t_list	*t;
	t_hex	*h;
	char	*s;

	t = *rec;
	while (t)
	{
		s = (char*)t->content;
		if (t->content_size && s[0] != 'L' && s[0] != '#')
			ft_check_relink(t, rec, hex);
		t = t->next;
	}
}
