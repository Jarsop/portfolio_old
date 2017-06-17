/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 02:15:25 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:27:28 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	ft_check(t_env *env)
{
	char	*tty;
	int		fd;

	tty = NULL;
	fd = -1;
	if (!isatty(0))
		exit(-1);
	while (++fd < 3)
	{
		if ((tty = ttyname(fd)))
			break ;
	}
	if (fd == 3)
		exit(-1);
	if ((env->fd = open(tty, O_RDWR)) < 0)
		exit(-1);
}

int		main(int ac, char **av, char **env)
{
	t_env	senv;
	int		i;

	g_ls = NULL;
	i = 0;
	if (ac > 1)
	{
		while (av[++i])
			ft_lspushend(&g_ls, av[i]);
		ft_readstd();
	}
	return (0);
}
