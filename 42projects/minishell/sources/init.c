/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:36:59 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/26 16:28:31 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_builtins(t_shell *shell)
{
	shell->built[CD].name = "cd";
	shell->built[CD].p = ft_cd;
	shell->built[ENV].name = "env";
	shell->built[ENV].p = ft_env;
	shell->built[SET].name = "setenv";
	shell->built[SET].p = ft_setenv;
	shell->built[UNSET].name = "unsetenv";
	shell->built[UNSET].p = ft_unsetenv;
	shell->built[HIST].name = "history";
	shell->built[HIST].p = ft_history;
}

void	ft_create_path(t_shell *shell)
{
	shell->path = (char**)ft_memalloc(sizeof(char*) * 6);
	shell->path[0] = ft_strdup("/usr/local/bin/");
	shell->path[1] = ft_strdup("/usr/bin/");
	shell->path[2] = ft_strdup("/bin/");
	shell->path[3] = ft_strdup("/usr/sbin/");
	shell->path[4] = ft_strdup("/sbin/");
	shell->path[5] = NULL;
}

void	ft_copyenv(t_shell *shell, char **env, int off)
{
	int		i;

	i = -1;
	while (env[++i])
		;
	shell->env = (char**)ft_memalloc(sizeof(char*) * (i + off + 1));
	i = -1;
	while (env[++i])
		shell->env[i] = ft_strdup(env[i]);
}

void	ft_create_env(t_shell *shell, char **env)
{
	char	buf[4096];
	int		i;

	if (env)
	{
		i = -1;
		ft_copyenv(shell, env, 0);
		while (shell->path[++i])
			shell->path[i] = ft_strwjoin(shell->path[i], "/", 0);
	}
	else
	{
		shell->env = (char**)ft_memalloc(sizeof(char*) * 5);
		shell->env[0] =
			ft_strdup("PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin");
		shell->env[1] = ft_strjoin("PWD=", getcwd(buf, 4096));
		shell->env[2] = ft_strwjoin("OLDPWD=", ft_findhome(), 1);
		shell->env[3] = ft_strwjoin("HOME=", ft_findhome(), 1);
		shell->env[4] = NULL;
	}
}

void	ft_initenv(t_shell *shell, char **env)
{
	int		i;

	i = -1;
	if (*env)
	{
		while (env[++i])
		{
			if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
					env[i][3] == 'H' && env[i][4] == '=')
			{
				shell->path = ft_strsplit(&env[i][5], ':');
				ft_create_env(shell, env);
				shell->home = ft_findhome();
				return ;
			}
		}
		ft_create_path(shell);
		return ;
	}
	else
	{
		ft_create_env(shell, NULL);
		ft_create_path(shell);
	}
	shell->home = ft_findhome();
}
