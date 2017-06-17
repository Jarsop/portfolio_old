/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:27:52 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/26 16:49:57 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_chkbuiltin(t_shell *shell, char *cmd)
{
	int		i;

	if (cmd)
	{
		if (!ft_strcmp("exit", cmd))
			return (ft_exit(shell));
		i = -1;
		while (++i < 5)
		{
			if (!ft_strcmp(shell->built[i].name, cmd))
			{
				shell->built[i].p(shell);
				return (1);
			}
		}
	}
	return (0);
}

int		ft_execute(t_shell *shell, char *path, int off)
{
	if (!off && execve(path, shell->av, shell->env) == -1)
		return (1);
	else if (off && execve(path, shell->av, NULL) == -1)
		return (1);
	else
		return (0);
}

int		ft_exec(t_shell *shell, int off)
{
	shell->status = 0;
	if ((shell->pid = fork()) != -1)
	{
		if (shell->pid == 0)
		{
			ft_helpexec(shell, off);
			exit(0);
		}
		else
		{
			shell->pids = wait(&shell->status);
			return (shell->status);
		}
	}
	else
		exit(0);
	return (1);
}

char	**ft_cleantabspace(char **tab)
{
	char	*s;
	char	*tmp;
	int		i;

	i = -1;
	while (tab[++i])
	{
		s = tab[i];
		if ((tmp = ft_strtrim(tab[i])))
		{
			tab[i] = tmp;
			ft_memdel((void**)&s);
		}
	}
	return (tab);
}

void	ft_shell(t_shell *shell)
{
	char	*buf;
	char	*tmp;
	char	pwd[4096];

	buf = NULL;
	while (get_next_line(0, &buf) > 0)
	{
		if (*buf)
		{
			tmp = buf;
			buf = ft_strtrim(buf);
			ft_memdel((void**)&tmp);
			ft_lstpushend(&(shell->buffer), buf, ft_strlen(buf));
			buf = ft_tild(shell->home, buf);
			ft_multicmd(shell, buf);
		}
		ft_prompt();
	}
	exit(0);
}
