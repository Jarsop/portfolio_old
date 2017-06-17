/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 09:43:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/25 17:42:11 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

# define LS_TAB 9

# define LS_L  0x00000001
# define LS_RR 0x00000002
# define LS_A  0x00000004
# define LS_R  0x00000008
# define LS_T  0x00000010
# define LS_GG 0x00000020
# define LS_F  0x00000040
# define LS_UN 0x00000080
# define LS_FF 0x00000100

typedef	struct stat	t_stat;
typedef	struct group	t_group;
typedef	struct passwd	t_passwd;
typedef	struct dirent	t_dirent;

typedef	struct			s_f
{
	char	f;
	int		m;
}						t_f;

typedef	struct			s_size
{
	int		nlink;
	int		usr;
	int		grp;
	int		block;
	int		min;
	int		maj;
	int		time;
	int		path;
}						t_size;

typedef	struct			s_ls
{
	t_stat		*stat;
	t_group		*group;
	t_passwd	*passwd;
	char		*name;
	char		*realname;
	int			err;
	int			ret;
	char		*right;
	char		*pname;
	char		*gname;
	char		*serrno;
	char		lnk[1024];
	size_t		minor;
	size_t		major;
	size_t		mt;
	char		*mtime;
	struct s_ls	*next;
}						t_ls;

int						g_m;
int						g_t;
char					*g_perm;
void					ft_opendir(t_ls **ls, char *path);
void					ft_opendircur(char *name);
void					ft_lsstart(int ac, char **av, t_f *f);
t_ls					*ft_lsnew(char const *name, char *realname);
void					ft_lspushback(t_ls **alst, char const *name,
						char *realname);
void					ft_lspushbackr(t_ls **alst, char const *name,
						char *realname);
void					ft_lstrit(t_ls **alst, char const *name,
						char *realname);
void					ft_lstritr(t_ls **alst, char const *name,
						char *realname);
void					ft_lspush(t_ls **alst, char const *name,
						char *realname);
void					ft_job(char **av, int ac, t_f *f);
void					ft_lsfree(t_ls *ls);
char					*ft_right(mode_t st_m);
void					ft_putls(t_ls **ls);
void					ft_putlsl(t_ls **ls);
void					ft_putl(t_ls *t, t_size s);
void					ft_psp(int nb);
t_size					ft_size(t_ls **ls);
int						ft_sizen(int nb);
void					ft_init_size(t_size *s);
void					ft_recuparg(t_ls **ls, int ac, char **av);
void					ft_recupdata(t_ls **ls);
void					ft_perm(t_ls *ls);
void					ft_perm2(t_ls *ls);
t_size					ft_size(t_ls **ls);
void					ft_putcolor(t_ls *t, char *p, int i);
char					ft_def(t_ls *t);
void					ft_helpopen(t_ls **ls, char *path, char *name);
void					ft_puts(t_ls **ls);
void					ft_help1(t_ls *t, char *p, char *c, int m);
void					ft_help3(t_ls *t, char *c, int m);
void					ft_help0(t_ls *t, char *p, char *c, int m);

#endif
