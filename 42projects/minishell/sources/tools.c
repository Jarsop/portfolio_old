/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:21:46 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/26 16:49:59 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_chdir(t_shell *shell, char *path)
{
	chdir(path);
	ft_newpwd(shell);
}

void	ft_helpexec(t_shell *shell, int off)
{
	int		i;
	char	*p;

	i = -1;
	while (shell->path[++i])
	{
		p = ft_strjoin(shell->path[i], shell->av[0]);
		ft_execute(shell, p, off);
		ft_memdel((void**)&p);
	}
	if (shell->av[0] && !(shell->path[i]) &&
			ft_execute(shell, shell->av[0], off))
	{
		ft_fprintf(2, "Minishell: command not found: %s\n", shell->av[0]);
		shell->ret = 1;
	}
}

void	ft_execenv(t_shell *shell)
{
	char	**tmp;
	int		i;
	int		j;

	if (!ft_strcmp(shell->av[1], "-i") && shell->av[2])
	{
		i = -1;
		while (shell->av[++i])
			;
		tmp = shell->av;
		shell->av = (char**)ft_memalloc(sizeof(char*) * i - 2);
		i = 1;
		j = -1;
		while (tmp[++i])
			shell->av[++j] = ft_strdup(tmp[i]);
		ft_freestab(tmp);
		ft_exec(shell, 1);
	}
}

void	ft_refreshenv(t_shell *shell)
{
	char	**e;

	e = NULL;
	if (!ft_strcmp("PATH", shell->av[1]))
	{
		e = shell->env;
		ft_freestab(shell->path);
		ft_strdel(&(shell->home));
		ft_initenv(shell, e);
		ft_freestab(e);
	}
	else if (!ft_strcmp("HOME", shell->av[1]))
	{
		ft_strdel(&(shell->home));
		shell->home = ft_strdup(ft_tovar(shell, "HOME"));
	}
}
