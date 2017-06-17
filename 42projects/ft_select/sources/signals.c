/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 20:04:55 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:24:34 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_check_sig(int sig)
{
	if (sig == SIGINT ||
		sig == SIGCONT ||
		sig == SIGTSTP ||
		sig == SIGWINCH ||
		sig == SIGTERM)
		return (1);
	else
		return (0);
}

void	ft_sig(int sig)
{
	t_env	*env;

	env = ft_singleton();
	if (sig == SIGINT || sig == SIGTERM)
		ft_sigintterm(env);
	else if (sig == SIGCONT)
		ft_sigcont(env);
	else if (sig == SIGTSTP)
		ft_sigtstp(env);
	else if (sig == SIGWINCH)
		ft_sigwinch(env);
}

void	ft_signal(void)
{
	int		i;
	int		sig;

	sig = 0;
	while (++sig <= 31)
	{
		i = 0;
		if ((i = ft_check_sig(sig)))
			signal(sig, ft_sig);
		else
			signal(sig, SIG_IGN);
	}
}
