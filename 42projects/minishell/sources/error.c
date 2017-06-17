/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 00:45:16 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/14 04:51:22 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cderr(int i, char *path)
{
	i = 0;
	ft_fprintf(2, "cd: %s: Can't acces to directory,"
			" maybe is not directory or directory"
			" not found or you have not rights.\n", path);
}

int		ft_seterr(t_shell *s)
{
	int		i;

	i = -1;
	while (s->av[++i])
		;
	if (i == 1)
	{
		ft_env(s);
		return (1);
	}
	if (i > 3)
	{
		ft_error("setenv: Too many arguments.\n");
		return (1);
	}
	else if (ft_strchr(s->av[1], '=') ||
			(s->av[2] && ft_strchr(s->av[2], '=')))
	{
		ft_error("setenv: Var name must contain alphanumeric characters.\n");
		return (1);
	}
	return (0);
}

void	ft_findvar(t_shell *shell, int n)
{
	char	**s;
	int		i;
	int		b;

	i = -1;
	while (shell->env[++i])
	{
		b = -1;
		while (shell->env[i][++b] != '=')
			;
		if (ft_strnstr(shell->env[i], shell->av[n], b) &&
				shell->env[i][ft_strlen(shell->av[n])] == '=')
		{
			shell->env = ft_helpfvar(shell, n, b, i);
			return ;
		}
	}
}

void	*ft_var(char *var, void *cmp, char *cnt, int off)
{
	int		i;

	i = -1;
	if (off <= 0)
	{
		while (((char*)cmp)[++i] && ((char*)cmp)[i] != '=')
			;
		if (ft_strnstr((char*)cmp, var, i) &&
				((char*)cmp)[ft_strlen(var)] == '=')
		{
			if (!off)
				cmp = ft_sfprintf(cmp, "%s=%s", var, cnt ? cnt : "\0");
			return (cmp);
		}
		return (NULL);
	}
	else
		return (ft_helpvar((t_shell*)cmp, var, cnt));
}
