/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:13:58 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:29:03 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_reprint(t_env *env)
{
	ft_clearjob(&(env->lenjob), &(env->hjob), 0);
	env->lenmax = ft_lslenmax(&g_ls);
	ft_putjob(&g_ls, env);
}

void	ft_print(t_env *env)
{
	t_ws	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	env->col = ws.ws_col;
	env->line = ws.ws_row;
	env->lenmax = ft_lslenmax(&g_ls);
	ft_putjob(&g_ls, env);
}

void	ft_actions(t_env *env, unsigned long buf)
{
	if (buf == ESC)
	{
		ft_restore_term(env);
		close(env->fd);
		exit(0);
	}
	if (buf == DEL)
	{
		if (ft_delselect(&g_ls))
		{
			ft_restore_term(env);
			close(env->fd);
			exit(0);
		}
		ft_reprint(env);
	}
	if (buf == ENTER)
	{
		ft_restore_term(env);
		ft_putselect(&g_ls, 1);
		close(env->fd);
		exit(0);
	}
}

void	ft_move(t_env *env, unsigned long buf)
{
	if (buf == DOWN)
	{
		ft_select_down(&g_ls, env);
		ft_reprint(env);
	}
	if (buf == UP)
	{
		ft_select_up(&g_ls, env);
		ft_reprint(env);
	}
	if (buf == RIGHT)
	{
		ft_select_r(&g_ls);
		ft_reprint(env);
	}
	else if (buf == LEFT)
	{
		ft_select_l(&g_ls);
		ft_reprint(env);
	}
	else if (buf == SPC)
	{
		ft_select_s(&g_ls);
		ft_reprint(env);
	}
}
