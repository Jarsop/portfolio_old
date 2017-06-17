/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:36:35 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/20 14:53:41 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	ft_affhist(t_sh *sh, t_ldst **hist, int n)
{
	t_ldst	*tmp;
	int		i;

	i = 0;
	tmp = *hist;
/*	if (!n)
	{
		sh->buf.buf = (char*)ft_memalloc(sizeof(char));
		sh->buf.size = 0;
		sh->buf.p = 0;
		sh->buf.pos = ft_get_cursor();
	}
*/	while (tmp && ++i < n)
		tmp = tmp->next;
	if (tmp)
	{
		sh->buf.origin = ft_get_cursor();
		ft_putmemory(tmp->content, tmp->content_size);
		sh->buf.buf = ft_strdup(tmp->content);
		sh->buf.size = tmp->content_size;
		sh->buf.p = tmp->content_size;
		sh->buf.h = (sh->buf.size + 3) / sh->l;
		sh->buf.pos.y = sh->buf.h;
		sh->buf.pos.x = (sh->buf.p) % sh->l;
	ft_fprintf(sh->fddebug, "\n-----------------------------\n");
	ft_fprintf(sh->fddebug, "origin x: %d\noriginy : %d\nbuf size%d\npos%d\npos y:%d\npos x : %d\nh : %d\n\n",
			sh->buf.origin.x, sh->buf.origin.y, sh->buf.size, sh->buf.p, sh->buf.pos.x, sh->buf.pos.y, sh->buf.h);
	ft_fprintf(sh->fddebug, "\n-----------------------------\n");
	}
}

void	ft_key_bind(t_sh *sh, unsigned long buf)
{
	if (buf == LEFT && sh->buf.p)
	{
		ft_caps("le", 0);
		--sh->buf.p;
		if (!((sh->buf.p + 3) % sh->l))
		{
			--sh->buf.pos.y;
			sh->buf.pos.x = sh->l - (!sh->buf.pos.y ? 3 : 0);
			ft_fprintf(sh->fddebug, "SUPP NEWLINE\n");
		}
		else
			--sh->buf.pos.x;
	}
	else if (buf == RIGHT && sh->buf.p < sh->buf.size)
	{
		ft_caps("nd", 0);
		++sh->buf.p;
		if (!((sh->buf.p + 3) % sh->l))
		{
			++sh->buf.pos.y;
			sh->buf.pos.x = -3;
			ft_putchar('\n');
			ft_fprintf(sh->fddebug, "NEWLINE\n");
		}
		else
			++sh->buf.pos.x;
	}
	else if (buf == UP && sh->hist.pos_elem < sh->hist.nb_elem && sh->buf.size == sh->buf.p)
	{
		++sh->hist.pos_elem;
		if (sh->buf.buf)
		{
			ft_goto(sh->buf.origin.x, sh->buf.origin.y);
			ft_caps("cd", 0);
		}
		ft_affhist(sh, &sh->hist.hist, sh->hist.pos_elem);
	}
	else if (buf == DOWN && sh->hist.pos_elem - 1 && sh->buf.size == sh->buf.p)
	{
		--sh->hist.pos_elem;
		if (sh->buf.buf)
		{
			ft_goto(sh->buf.origin.x, sh->buf.origin.y);
			ft_caps("cd", 0);
		}
		ft_affhist(sh, &sh->hist.hist, sh->hist.pos_elem);
	}
	else if (buf == OUP && sh->buf.h)
	{
		if (sh->buf.pos.y > 0 && sh->buf.p - sh->l >= 0)
		{
			--sh->buf.pos.y;
			sh->buf.p -= sh->l;
			ft_caps("up", 1);
			ft_fprintf(sh->fddebug, "\n\nUP\n\n\n\npos.x : %d\npos.y : %d\npos : %d\nh : %d\nlne win : %d \n\n", sh->buf.pos.x, sh->buf.pos.y, sh->buf.p, sh->buf.h, sh->l);
		}
	}
	else if (buf == ODOWN && sh->buf.h)
	{
		if (sh->buf.pos.y < sh->buf.h)
		{
			++sh->buf.pos.y;
			if (sh->buf.pos.y == sh->buf.h && sh->buf.p + sh->l > sh->buf.size)
			{
				ft_fprintf(sh->fddebug, "yolooooooooooo\n");
				sh->buf.pos.x = sh->buf.size % sh->l;
				sh->buf.p = sh->buf.size;
			ft_goto(sh->buf.origin.x + sh->buf.pos.x, sh->buf.origin.y - 1+ sh->buf.pos.y);
			}
			else
				sh->buf.p += sh->l;
			ft_printf("\033[B");
			ft_fprintf(sh->fddebug, "\n\nDOWN\n\n\n\npos.x : %d\npos.y : %d\npos : %d\nh : %d\nlne win : %d \n\n", sh->buf.pos.x, sh->buf.pos.y, sh->buf.p, sh->buf.h, sh->l);
		}
	}
}
