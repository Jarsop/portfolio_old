/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 17:07:03 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/20 14:02:18 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <libft.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <pwd.h>

# define UP      4283163
# define DOWN    4348699
# define LEFT    4479771
# define RIGHT   4414235
# define CUP     71696882162459
# define OUP     1096489755
# define CDOWN   72796393790235
# define ODOWN   1113266971
# define CLEFT   74995417045787
# define OLEFT   1146821403
# define CRIGHT  73895905418011
# define ORIGHT  1130044187
# define HOME    4741915
# define END     4610843
# define DEL     127
# define ENTER   10
# define ESC     27
# define SPC     32

typedef struct	s_sh	t_sh;
typedef struct	termios	t_term;
typedef struct	winsize	t_ws;
typedef struct	s_terms	t_terms;
typedef struct	s_cmd	t_cmd;
typedef struct	s_buf	t_buf;
typedef struct	s_hist	t_hist;
typedef struct	s_focus	t_focus;

struct					s_terms
{
	t_term	cur;
	t_term	save;
};

struct					s_cmd
{
	char	**args;
	char	**env;
	char	*cmd;
};

struct					s_focus
{
	int		x;
	int		y;
};

struct					s_hist
{
	t_ldst	*hist;
	int		pos_elem;
	int		nb_elem;
};

struct					s_buf
{
	t_focus	origin;
	t_focus	pos;
	char	*buf;
	int		p;
	int		size;
	int		h;
	int		l;
};

struct					s_sh
{
	t_hist		hist;
	t_buf		buf;
	t_terms		term;
	t_focus		focus;
	char		**env;
	int			fddebug;
	int			h;
	int			l;
};

void					ft_prompt(int i);
void					ft_putmemory(void *data, size_t size);

void					ft_caps(char *cmd, int fd);
t_focus					ft_get_cursor(void);
int						ft_arround(float nb);

void					ft_key_bind(t_sh *sh, unsigned long buf);

void					ft_goto(int x, int y);
t_sh					*ft_singleton(void);
void					ft_replace_focus(size_t size, size_t focus);
void					ft_make_it(t_sh *sh);
int						ft_init_term(t_sh *sh);
void					ft_restore_term(t_term save);
int						ft_readstd(t_sh *sh);
void					ft_delprint(size_t size, size_t focus);

#endif
