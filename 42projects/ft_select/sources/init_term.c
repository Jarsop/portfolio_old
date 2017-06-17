/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 17:34:18 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:22:38 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_env	*ft_singleton(void)
{
	static t_env	*env = NULL;

	if (!env)
	{
		env = (t_env *)ft_memalloc(sizeof(t_env));
		if (ft_init_term(env) < 0)
			return (NULL);
	}
	return (env);
}

void	ft_restore_term(t_env *env)
{
	ft_clearjob(&(env->lenjob), &(env->hjob), 0);
	if (tcsetattr(0, TCSADRAIN, &(env->save)) < 0)
		return ;
	ft_caps("ve", env->fd);
	ft_caps("ve", 0);
}

int		ft_init_term(t_env *env)
{
	ft_check(env);
	env->hjob = 0;
	env->lenjob = 0;
	if (tgetent(NULL, getenv("TERM")) < 1 && tgetent(NULL, "xterm") < 1)
		return (-1);
	if (tcgetattr(env->fd, &(env->term)) == -1)
		return (-1);
	if (tcgetattr(env->fd, &(env->save)) == -1)
		return (-1);
	env->term.c_lflag &= ~(ICANON | ECHO);
	env->term.c_cc[VMIN] = 0;
	env->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(env->term)) < 0)
		return (-1);
	ft_caps("vi", env->fd);
	ft_caps("vi", 0);
	return (0);
}
