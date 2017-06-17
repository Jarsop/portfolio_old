/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:19:16 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/23 10:39:39 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_history(void *shell)
{
	t_list	*t;
	int		i;

	t = (t_list*)((t_shell*)shell)->buffer;
	if (t)
	{
		i = 0;
		t = ft_lstlast(t);
		while (t)
		{
			++i;
			ft_printf("[%d]: %s\n", i, t->content);
			t = t->prev;
		}
	}
	else
		ft_error("Minishell: No history.\n");
}

void	ft_changepwd(t_shell *shell, char **find, int *i)
{
	char	buf[4096];
	char	*s;

	shell->env[i[1]] = ft_strjoin("OLDPWD=", &(find[1])[4]);
	getcwd(buf, 4096);
	shell->env[i[2]] = ft_strjoin("PWD=", buf);
	if (find[0])
		ft_memdel((void**)&find[0]);
	if (find[1])
		ft_memdel((void**)&find[1]);
}

void	ft_multicmd(t_shell *shell, char *cmd)
{
	char	**multi;
	int		i;

	i = -1;
	multi = NULL;
	multi = ft_strsplit(cmd, ';');
	ft_memdel((void**)&cmd);
	multi = ft_cleantabspace(multi);
	while (multi[++i])
	{
		if (!ft_checkandor(shell, multi[i]))
		{
			shell->av = ft_strsplit(multi[i], ' ');
			shell->av = ft_cleantabspace(shell->av);
			if (!ft_chkbuiltin(shell, shell->av[0]))
				ft_exec(shell, 0);
			if (shell->av && shell->av[0])
				ft_freestab(shell->av);
		}
	}
	if (multi && multi[0])
		ft_freestab(multi);
}

void	ft_newpwd(t_shell *shell)
{
	char	*find[2];
	int		i[3];

	i[0] = -1;
	find[0] = NULL;
	find[1] = NULL;
	while (shell->env[++i[0]])
	{
		if (shell->env[i[0]][0] == 'O' && shell->env[i[0]][1] == 'L' &&
			shell->env[i[0]][2] == 'D' && shell->env[i[0]][3] == 'P' &&
			shell->env[i[0]][4] == 'W' && shell->env[i[0]][5] == 'D' &&
			shell->env[i[0]][6] == '=')
		{
			find[0] = shell->env[i[0]];
			i[1] = i[0];
		}
		if (shell->env[i[0]][0] == 'P' && shell->env[i[0]][1] == 'W' &&
			shell->env[i[0]][2] == 'D' && shell->env[i[0]][3] == '=')
		{
			find[1] = shell->env[i[0]];
			i[2] = i[0];
		}
	}
	find[0] && find[1] ? ft_changepwd(shell, find, i) : 0;
}

char	*ft_oldpwd(t_shell *shell)
{
	int		i;

	i = -1;
	while (shell->env[++i])
	{
		if (shell->env[i][0] == 'O' && shell->env[i][1] == 'L' &&
			shell->env[i][2] == 'D' && shell->env[i][3] == 'P' &&
			shell->env[i][4] == 'W' && shell->env[i][5] == 'D' &&
			shell->env[i][6] == '=')
			return (&(shell->env[i])[7]);
	}
	return ("/");
}
