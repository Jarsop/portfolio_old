/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:23:08 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/24 14:55:59 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_nbparam(char const *s, char c)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
		{
			while (s[j] == c)
				j++;
			i++;
		}
		j++;
	}
	return (i);
}

static int	ft_lenparam(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s == c)
		{
			if (j >= i)
			{
				i = j;
				j = 0;
			}
			j = 0;
		}
		s++;
		j++;
	}
	return (i);
}

static char	**malloctab(char const *s, char c)
{
	int		i;
	char	**words;

	i = 0;
	words = (char **)ft_memalloc(sizeof(char*) * (ft_nbparam(s, c) + 1));
	while (i != ft_nbparam(s, c))
	{
		words[i] = (char *)ft_memalloc(sizeof(char) * (ft_lenparam(s, c) + 1));
		i++;
	}
	return (words);
}

static void	ft_populate_tab(char **words, char *s1, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (s1[++i] != '\0')
	{
		if (s1[i] == c)
		{
			while (s1[i] == c)
				i++;
			i--;
			k++;
			j = 0;
		}
		else
			words[k][j++] = s1[i];
	}
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*s1;
	int		test;

	s1 = ft_strtrimy(s, c);
	if (!s1)
		return (NULL);
	test = ft_strlen(s1);
	if (test == 0)
	{
		words = ft_memalloc(sizeof(char*) * 1);
		words[0] = NULL;
		return (words);
	}
	words = malloctab(s1, c);
	ft_populate_tab(words, s1, c);
	return (words);
}
