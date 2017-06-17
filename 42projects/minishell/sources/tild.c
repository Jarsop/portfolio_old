/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tild.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 01:34:22 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/19 17:33:16 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*ft_freetild(char *buf, char *home, int i)
{
	char	*tmp;
	char	*t2;

	if (i && buf[i + 1])
	{
		t2 = buf;
		tmp = ft_strndup(buf, i);
		buf = ft_sprintf("%s%s%s", tmp, home, &buf[i + 1]);
		ft_memdel((void**)&t2);
	}
	else if (i)
	{
		t2 = buf;
		tmp = ft_strndup(buf, i);
		buf = ft_sprintf("%s%s", tmp, home);
		ft_memdel((void**)&t2);
	}
	else
	{
		tmp = buf;
		buf = ft_strjoin(home, &buf[i + 1]);
	}
	ft_memdel((void**)&tmp);
	return (buf);
}

static char	*ft_replace_tild(char *home, char *buf)
{
	int		i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '~')
		{
			buf = ft_freetild(buf, home, i);
			break ;
		}
	}
	return (buf);
}

char		*ft_tild(char *home, char *buf)
{
	int		i;
	int		t;

	i = -1;
	t = 0;
	while (buf[++i])
	{
		if (buf[i] == '~')
			++t;
	}
	while (t--)
		buf = ft_replace_tild(home, buf);
	return (buf);
}
