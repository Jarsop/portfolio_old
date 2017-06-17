/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:06:44 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:27:10 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_sigintterm(t_env *env)
{
	ft_restore_term(env);
	close(env->fd);
	exit(0);
}

void	ft_sigcont(t_env *env)
{
	signal(SIGTSTP, ft_sig);
	ft_init_term(env);
	ft_print(env);
}

void	ft_sigtstp(t_env *env)
{
	char	c[2];

	c[0] = env->term.c_cc[VSUSP];
	c[1] = 0;
	ft_restore_term(env);
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, c);
	ft_caps("dl", 0);
}

void	ft_sigwinch(t_env *env)
{
	t_ws	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	if (env->col != ws.ws_col || env->line != ws.ws_row)
	{
		ft_clearjob(&(env->lenjob), &(env->hjob), 0);
		ft_print(env);
	}
}
