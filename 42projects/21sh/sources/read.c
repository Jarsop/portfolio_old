/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:46:30 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/22 01:30:22 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	ft_putmemory(void *data, size_t size)
{
		write(1, data, size);
}

void	*ft_realloc(t_sh *sh, size_t dsize, size_t size, int off)
{
	char	*new;

	if (!(new = ft_memalloc(sizeof(char) * size + 1)))
		return (NULL);
	if (!off && dsize)
	{
		ft_memcpy(new, sh->buf.buf, sh->buf.p);
		if (sh->buf.p < sh->buf.size)
			ft_memcpy(&new[sh->buf.p + 1], &sh->buf.buf[sh->buf.p], size - sh->buf.p);
	}
	else if (dsize)
	{
		ft_memcpy(new, sh->buf.buf, sh->buf.p);
		if (sh->buf.p < sh->buf.size)
			ft_memcpy(&new[sh->buf.p - 1], &sh->buf.buf[sh->buf.p], dsize - sh->buf.p);
	}
	if (dsize)
		ft_memdel((void**)&sh->buf.buf);
	sh->buf.buf = new;
	return (new);
}

int		ft_isprintl(unsigned long c)
{
	if (c >= 0040 && c <= 0176)
		return (1);
	else
		return (0);
}

int		ft_arround(float nb)
{
	if (nb - (int)nb)
		return ((int)(nb + 1));
	return ((int)(nb));
}

int		ft_readstd(t_sh *sh)
{
	unsigned long	buf;
	t_ws			ws;

	while (42)
	{
		buf = 0;
		ioctl(0, TIOCGWINSZ, &ws);
		sh->l = ws.ws_col;
		sh->h = ws.ws_row;
		read(0, (char*)&buf, 8);
	/*	if (buf)
			ft_printf("%lu", buf);
	*/	if (buf && buf != UP && buf != DOWN)
			sh->hist.pos_elem = 0;
		if (buf && (ft_isprintl(buf) || buf == DEL))
		{
			if (buf == DEL && sh->buf.size && sh->buf.p)
			{
				sh->buf.buf = ft_realloc(sh, sh->buf.size, sh->buf.size - 1, 1);
				--sh->buf.p;
				if (!((sh->buf.p + 3) % sh->l))
				{
					if (sh->buf.origin.y + sh->buf.pos.y > sh->h)
					{
					ft_fprintf(sh->fddebug, "buf h : %d\npos y : %d\norignin y : %d\nsh h : %d\n", sh->buf.h, sh->buf.pos.y, sh->buf.origin.y, sh->h);
						--sh->buf.origin.y;
						ft_putchar('\n');
						ft_caps("le", 1);
					}
					--sh->buf.pos.y;
					//if (sh->buf.p == sh->buf.size && sh->buf.pos.y < sh->buf.h)
					//	sh->buf.h = sh->buf.pos.y;
					sh->buf.h = (sh->buf.size + 3) / sh->l;
					sh->buf.pos.x = sh->buf.pos.y ? -3 : 0;
					ft_fprintf(sh->fddebug, "SUPP NEWLINE\n");
				}
				else
					--sh->buf.pos.x;
				--sh->buf.size;
			}
			else if (buf != DEL)
			{
				sh->buf.buf = ft_realloc(sh, sh->buf.size, sh->buf.size + 1, 0);
				sh->buf.buf[sh->buf.p] = (unsigned char)buf;
				++sh->buf.p;
				if (!((sh->buf.p + 3) % sh->l))
				{
					++sh->buf.pos.y;
					if (sh->buf.origin.y + sh->buf.pos.y > sh->h)
					{
					ft_fprintf(sh->fddebug, "buf h : %d\npos y : %d\norignin y : %d\nsh h : %d\n", sh->buf.h, sh->buf.pos.y, sh->buf.origin.y, sh->h);
						--sh->buf.origin.y;
						ft_putchar('\n');
						ft_caps("le", 1);
					}
					if (sh->buf.pos.y > sh->buf.h)
						sh->buf.h = sh->buf.pos.y;
					sh->buf.pos.x = sh->buf.pos.y ? -3 : 0;
					ft_fprintf(sh->fddebug, "NEWLINE\n");
				}
				else
					++sh->buf.pos.x;
				++sh->buf.size;
			}
			ft_goto(sh->buf.origin.x, sh->buf.origin.y);
			ft_caps("cd", 0);
			ft_putmemory(sh->buf.buf, sh->buf.size);
			ft_goto(sh->buf.origin.x + sh->buf.pos.x, sh->buf.origin.y + sh->buf.pos.y);
		}
		else if (buf == ENTER)
			ft_make_it(sh);
		else
			ft_key_bind(sh, buf);
	}
	return (0);
}

void	ft_restore_term(t_term save)
{
	if (tcsetattr(0, TCSADRAIN, &save) < 0)
		return ;
}

int		ft_init_term(t_sh *sh)
{
	if (tgetent(NULL, getenv("TERM")) < 1 && tgetent(NULL, "xterm") < 1)
		return (-1);
	if (tcgetattr(0, &(sh->term.cur)) == -1)
		return (-1);
	if (tcgetattr(0, &(sh->term.save)) == -1)
		return (-1);
	sh->term.cur.c_lflag &= ~(ICANON | ECHO);
	sh->term.cur.c_cc[VMIN] = 1;
	sh->term.cur.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(sh->term.cur)) < 0)
		return (-1);
	sh->buf.origin = ft_get_cursor();
	return (0);
}
