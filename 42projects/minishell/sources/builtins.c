/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:09:23 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/26 16:23:09 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_exit(t_shell *shell)
{
	if (shell->av[1])
	{
		ft_error("exit: error Synthax\n");
		shell->ret = -1;
		return (1);
	}
	else
		exit(0);
}

void	ft_cd(void *content)
{
	t_shell	*shell;
	char	tmp[4096];
	int		i;
	int		n;

	n = 0;
	shell = (t_shell*)content;
	if (!shell->av[1])
		ft_chdir(shell, shell->home);
	while (shell->av[++n])
	{
		if (!ft_strcmp(shell->av[n], "-"))
			ft_chdir(shell, ft_oldpwd(shell));
		else if ((i = chdir(shell->av[n])) < 0)
		{
			ft_putendl(shell->av[n]);
			shell->ret = -1;
			ft_cderr(i, shell->av[n]);
			ft_chdir(shell, getcwd(tmp, 4096));
			break ;
		}
		else
			ft_newpwd(shell);
	}
}

void	ft_env(void *content)
{
	t_shell	*shell;

	shell = (t_shell*)content;
	if (shell->av[1])
		ft_execenv(shell);
	else
	{
		if (shell->env && *shell->env)
			ft_print_words_tables(shell->env);
		else
			ft_error("Minishell: No environement set\n");
	}
}

void	ft_setenv(void *content)
{
	t_shell	*s;
	int		i;
	int		r;

	i = -1;
	s = (t_shell*)content;
	if (ft_seterr(s))
		return ;
	i = -1;
	while (s->env[++i])
	{
		if (ft_var(s->av[1], s->env[i], s->av[2] ? s->av[2] : NULL, -1))
		{
			s->env[i] = ft_var(s->av[1], s->env[i],
					s->av[2] ? s->av[2] : NULL, 0);
			ft_refreshenv(s);
			return ;
		}
	}
	s->env = (char**)ft_var(s->av[1], s, s->av[2] ? s->av[2] : NULL, 1);
	ft_refreshenv(s);
}

void	ft_unsetenv(void *content)
{
	t_shell	*s;
	int		i;

	i = -1;
	s = (t_shell*)content;
	while (s->av[++i])
		;
	if (i == 1)
	{
		s->ret = -1;
		ft_error("unsetenv: Too few arguments.\n");
	}
	i = 0;
	while (s->av[++i])
		ft_findvar(s, i);
}
