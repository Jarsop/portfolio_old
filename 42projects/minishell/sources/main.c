/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:30:18 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/09 03:45:09 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_prompt(int i)
{
	char	pwd[4096];

	i = 0;
	ft_printf("\n%s in \033[31m%s\033[33m\n$> \033[0m", PROMPT,
		getcwd(pwd, 4096) ? getcwd(pwd, 4096) : "\0");
}

void	ft_initshell(t_shell *shell)
{
	shell->buffer = NULL;
	shell->env = NULL;
	shell->path = NULL;
	shell->av = NULL;
	shell->home = NULL;
	shell->ret = 0;
	shell->pids = 0;
}

int		main(int ac, char **av, char **env)
{
	t_shell	*shell;

	ft_prompt(1);
	signal(SIGINT, ft_prompt);
	if (!(shell = (t_shell*)ft_memalloc(sizeof(t_shell))))
		exit(0);
	ft_initshell(shell);
	ft_init_builtins(shell);
	ft_initenv(shell, env);
	ft_shell(shell);
	return (0);
}
