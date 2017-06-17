/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 18:36:43 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/22 02:37:42 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
int					ft_atoi_base(char *str, char *base);
long				ft_atol_base(char *str, char *base);
char				*ft_btoa(void *data, int type, int w);
void				ft_bzero(void *s, size_t n);
void				ft_chrswap(char *a, char *b);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_dtobin(double dbl);
void				ft_error(char const *s);
int					ft_find_next_prime(int nb);
char				*ft_htoa(short n);
int					ft_is_prime(int nb);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_iswap(int *a, int *b);
char				*ft_itoa(int n);
char				*ft_itoa_base(long n, char *base);
t_list				*ft_lstat(t_list *alst, size_t nbr);
t_list				*ft_lstlast(t_list *alst);
void				ft_lstpushback(t_list **alst, void const *content,
					size_t content_size);
void				ft_lstpushend(t_list **alst, void const *content,
					size_t content_size);
int					ft_lstsize(t_list **alst);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstclrone(t_list **begin);
void				ft_lstclrlast(t_list **begin);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstend(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long n, char *base);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_printf(const char *format, ...);
int					ft_fprintf(int fd, const char *format, ...);
void				ft_print_words_tables(char **tab);
void				ft_printbtoa(char *str, int type);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putlong(long n);
void				ft_putnbr(int n);
void				ft_putnbr_base(int nb, char *base);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					ft_recursive_factorial(int nb);
int					ft_recursive_power(int nb, int power);
int					ft_sqrt(int nb);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
int					ft_strdigit(char *str);
char				*ft_strdup(const char *s1);
char				*ft_strdupclr(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strndup(const char *s1, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnjoin(const char *s1, const char *s2, size_t len);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnrstr(const char *s1, const char *s2, size_t ni);
int					ft_strnstrct(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcstr(const char *s1, const char *s2, char c);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strstrct(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strtrimy(char const *s, char y);
char				*ft_strwjoin(char const *s1, char const *s2, size_t a);
char				*ft_strwnjoin(char const *s1, char const *s2,
					size_t len, size_t a);
int					ft_tolower(int c);
int					ft_toupper(int c);
unsigned long		ft_ulpower(unsigned long nbr, unsigned long power);
char				*ft_ultoa(unsigned long n);
char				*ft_ultoa_base(unsigned long nb, char *base);
int					get_next_line(int const fd, char **line);

#endif
