/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 15:40:39 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/19 17:04:57 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_tovar(t_shell *shell, char *var)
{
	int		i;
	int		c;

	i = -1;
	c = -1;
	while (shell->env[++i])
	{
		if (ft_strnstr(shell->env[i], var, ft_strlen(var)) &&
				shell->env[i][ft_strlen(var)] == '=')
		{
			while (shell->env[i][++c] != '=')
				;
			return (&shell->env[i][c + 1]);
		}
	}
	return (NULL);
}

char	*ft_findhome(void)
{
	char			path[4096];
	struct stat		*s;
	struct passwd	*pw;

	getcwd(path, 4096);
	s = (struct stat*)ft_memalloc(sizeof(struct stat));
	if (stat(path, s) != -1)
	{
		pw = getpwuid(s->st_uid);
		ft_memdel((void**)&s);
		return (ft_strdup(pw->pw_dir));
	}
	ft_memdel((void**)&s);
	return (ft_strdup(path));
}

char	**ft_helpvar(t_shell *shell, char *var, char *cnt)
{
	char	**e;
	int		i;

	i = -1;
	while (shell->env[++i])
		;
	e = shell->env;
	ft_copyenv(shell, e, 1);
	ft_freestab(e);
	shell->env[i] = ft_sprintf("%s=%s", var, cnt ? cnt : "\0");
	return (shell->env);
}

char	**ft_helpfvar(t_shell *shell, int n, int b, int i)
{
	char	**s;
	int		len;
	int		cnt;
	int		del;

	len = -1;
	cnt = -1;
	del = 0;
	s = shell->env;
	while (shell->env[++len])
		;
	shell->env = (char**)ft_memalloc(sizeof(char*) * len--);
	while (++cnt < len)
	{
		if (ft_strnstr(s[cnt], shell->av[n], b) &&
			s[cnt][ft_strlen(shell->av[n])] == '=')
			del = 1;
		shell->env[cnt] = ft_strdup(s[cnt + del]);
	}
	ft_freestab(s);
	return (shell->env);
}
