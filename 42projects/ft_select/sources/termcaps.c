/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 20:06:02 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 18:06:28 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ft_putc(int c)
{
	write(0, &c, 1);
	return (0);
}

void	ft_caps(char *cmd, int fd)
{
	char	*str;

	str = NULL;
	if ((str = tgetstr(cmd, NULL)))
		tputs(str, 0, ft_putc);
}

void	ft_select(char *str, int fd)
{
	ft_caps("so", fd);
	ft_putstr_fd(str, fd);
	ft_caps("se", fd);
}

void	ft_cursor(char *str, int fd)
{
	ft_caps("us", fd);
	ft_putstr_fd(str, fd);
	ft_caps("ue", fd);
}

void	ft_curssel(char *str, int fd)
{
	ft_caps("us", fd);
	ft_caps("so", fd);
	ft_putstr_fd(str, fd);
	ft_caps("ue", fd);
	ft_caps("se", fd);
}
