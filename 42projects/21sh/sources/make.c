/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:50:44 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/19 21:46:43 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	ft_prompt(int i)
{
	char	pwd[4096];

	i = 0;
	ft_putstr("\033[36m");
	ft_printf("\n# \033[32m21sh\033[0m in \033[31m%s\033[33m\n$> \033[0m",
		getcwd(pwd, 4096) ? getcwd(pwd, 4096) : "\0");
}

void	ft_make_it(t_sh *sh)
{
	ft_fprintf(sh->fddebug, "\n-----------------------------\n");
	ft_fprintf(sh->fddebug, "x : %d\ny : %d\n", sh->buf.origin.x + sh->buf.size - sh->buf.pos.x, sh->buf.origin.y + sh->buf.h);
	ft_fprintf(sh->fddebug, "\n-----------------------------\n");
	ft_goto(sh->buf.origin.x + sh->buf.size - sh->buf.pos.x, sh->buf.origin.y + sh->buf.h);
	if (sh->buf.size)
	{
		++sh->hist.nb_elem;
		ft_ldstassend(&sh->hist.hist, sh->buf.buf, sh->buf.size);
		ft_bzero(&sh->buf, sizeof(t_buf));
		ft_bzero(&sh->focus, sizeof(t_focus));
	}
	ft_prompt(0);
	sh->buf.origin = ft_get_cursor();
}
