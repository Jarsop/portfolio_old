/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:08:36 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/19 16:44:51 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_sh	*ft_singleton(void)
{
	static t_sh	sh;
	static char	init = 0;

	if (!init)
	{
		ft_bzero(&sh, sizeof(t_sh));
		++init;
	}
	return (&sh);
}

int		main(int ac, char **av, char **env)
{
	t_sh	*sh;

	sh = ft_singleton();
	if (av[1] && !ft_strncmp(av[1], "debug=", 6))
		sh->fddebug = open(&av[1][6], O_RDWR);
	ft_prompt(0);
	if (!ft_init_term(sh))
	{
		sh->buf.origin = ft_get_cursor();
		ft_readstd(sh);
	}
	return (0);
}
