/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 15:17:41 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 18:51:23 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_readstd(void)
{
	t_env			*env;
	unsigned long	buf;

	if (!(env = ft_singleton()))
		exit(-1);
	ft_print(env);
	ft_signal();
	while (42)
	{
		ft_bzero((char*)&buf, 8);
		read(0, (char*)&buf, 8);
		ft_move(env, buf);
		ft_actions(env, buf);
	}
	return (0);
}
