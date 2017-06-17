/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:31:54 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/19 14:04:06 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		ft_putc(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

t_focus	ft_get_cursor(void)
{
	t_focus	focus;
	char	buf[16];
	char	*s;

	ft_caps("u7", 0);
	ft_bzero(buf, 16);
	s = buf;
	while (read(STDIN_FILENO, s, 1) >= 0 && *s != 'R')
		++s;
	s = buf;
	while (*s && !ft_isdigit(*s))
		++s;
	focus.y = ft_atoi(s);
	while (*s && ft_isdigit(*s))
		++s;
	while (*s && !ft_isdigit(*s))
		++s;
	focus.x = ft_atoi(s);
	return (focus);
}

void	ft_caps(char *cmd, int fd)
{
	char	*str;

	str = NULL;
	if ((str = tgetstr(cmd, NULL)))
		tputs(str, fd, ft_putc);
}

void	ft_goto(int x, int y)
{
	ft_printf("\033[%d;%df", y, x);
}
