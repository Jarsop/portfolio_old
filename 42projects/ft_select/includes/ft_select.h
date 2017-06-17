/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 17:20:01 by jgeslin           #+#    #+#             */
/*   Updated: 2016/09/15 19:40:26 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <termcap.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <fcntl.h>

# define CURSOR  0x01
# define SELECT  0x02
# define CURSSEL 0x03
# define VISIB   0x04
# define UP      4283163
# define DOWN    4348699
# define LEFT    4479771
# define RIGHT   4414235
# define DEL     127
# define ENTER   10
# define ESC     27
# define SPC     32

typedef struct termios	t_term;
typedef struct winsize	t_ws;

typedef struct			s_sl
{
	char				*str;
	int					len;
	char				opt;
	struct s_sl			*next;
	struct s_sl			*prev;
}						t_ls;

t_ls					*g_ls;

typedef struct			s_env
{
	t_term				term;
	t_term				save;
	size_t				hjob;
	size_t				lenjob;
	size_t				col;
	size_t				line;
	int					nbwl;
	int					nbwe;
	int					lenmax;
	int					fd;
}						t_env;

/*
*******************************Terminal****************************************
*/
int						ft_init_term(t_env *env);
void					ft_restore_term(t_env *env);
/*
*******************************Termcaps****************************************
*/
int						ft_putc(int c);
void					ft_caps(char *cmd, int fd);
/*
*********************************List******************************************
*/
void					ft_lspushend(t_ls **alst, char const *str);
int						ft_lslenmax(t_ls **ls);
void					ft_lsfreeone(t_ls *ls);
int						ft_lssize(t_ls **ls);
/*
********************************Print******************************************
*/
int						ft_readstd(void);
void					ft_putselect(t_ls **ls, int fd);
void					ft_clearjob(size_t *lenjob, size_t *hjob, int fd);
void					ft_putjob(t_ls **ls, t_env *env);
void					ft_helpput(t_env *env, t_ls *tmp, int *job);
void					ft_print(t_env *env);
void					ft_reprint(t_env *env);
void					ft_actions(t_env *env, unsigned long buf);
void					ft_move(t_env *env, unsigned long buf);
int						ft_lenmax(t_env *env, int *len, int *cnt);
/*
*******************************Select******************************************
*/
void					ft_select_r(t_ls **ls);
void					ft_select_l(t_ls **ls);
void					ft_select_s(t_ls **ls);
int						ft_delselect(t_ls **ls);
void					ft_select_up(t_ls **ls, t_env *env);
void					ft_select_down(t_ls **ls, t_env *env);
void					ft_check(t_env *env);
void					ft_curssel(char *str, int fd);
void					ft_cursor(char *str, int fd);
void					ft_select(char *str, int fd);
/*
*******************************Signaux*****************************************
*/
int						ft_check_sig(int sig);
void					ft_sig(int sig);
void					ft_signal(void);
t_env					*ft_singleton(void);
void					ft_sigwinch(t_env *env);
void					ft_sigtstp(t_env *env);
void					ft_sigcont(t_env *env);
void					ft_sigintterm(t_env *env);

#endif
