/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:36:38 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/26 16:37:43 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
**********************************Minishell************************************
*/

# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define PROMPT "\033[32mMinishell\033[0m"
# define CD 0
# define ENV 1
# define SET 2
# define UNSET 3
# define HIST 4

/*
***********************************Struct**************************************
*/

typedef	struct	s_built
{
	char	*name;
	void	(*p)(void *content);
}				t_built;

typedef	struct	s_shell
{
	t_list	*buffer;
	t_built	built[5];
	char	**env;
	char	**path;
	char	**av;
	char	*home;
	pid_t	pid;
	pid_t	pids;
	int		status;
	int		ret;
}				t_shell;

/*
************************************Init***************************************
*/

void			ft_initenv(t_shell *shell, char **env);
void			ft_init_builtins(t_shell *shell);
void			ft_copyenv(t_shell *shell, char **env, int off);
void			ft_shell(t_shell *shell);

/*
*********************************Execution*************************************
*/

void			ft_prompt();
int				ft_exec(t_shell *shell, int off);
void			ft_findvar(t_shell *shell, int n);
int				ft_chkbuiltin(t_shell *shell, char *cmd);
void			ft_execenv(t_shell *shell);
int				ft_execute(t_shell *shell, char *path, int off);

/*
***********************************Help****************************************
*/

char			**ft_helpvar(t_shell *shell, char *var, char *cnt);
char			**ft_helpfvar(t_shell *shell, int n, int b, int i);
void			ft_newpwd(t_shell *shell);
char			*ft_oldpwd(t_shell *shell);
char			**ft_cleantabspace(char **tab);
char			*ft_tovar(t_shell *shell, char *var);
void			ft_refreshenv(t_shell *shell);
void			ft_helpexec(t_shell *shell, int off);

/*
***********************************Error***************************************
*/

void			ft_cderr(int i, char *path);
void			*ft_var(char *var, void *cmp, char *cnt, int off);
int				ft_seterr(t_shell *shell);

/*
**********************************Builtins*************************************
*/

int				ft_exit(t_shell *shell);
void			ft_cd(void *content);
void			ft_chdir(t_shell *shell, char *path);
void			ft_env(void *content);
void			ft_setenv(void *content);
void			ft_unsetenv(void *content);
void			ft_history(void *lst);
void			ft_multicmd(t_shell *shell, char *cmd);
char			*ft_findhome(void);
char			*ft_tild(char *home, char *buf);
int				ft_checkandor(t_shell *shell, char *buf);

#endif
