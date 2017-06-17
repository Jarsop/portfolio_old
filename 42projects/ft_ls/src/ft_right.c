/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:31:03 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/24 16:44:34 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	ft_right2(mode_t st_m, char **buf)
{
	*buf = ft_strdup("----------");
	if (S_ISBLK(st_m))
		return ('b');
	else if (S_ISCHR(st_m))
		return ('c');
	else if (S_ISLNK(st_m))
		return ('l');
	else if (S_ISDIR(st_m))
		return ('d');
	else if (S_ISFIFO(st_m))
		return ('p');
	else if (S_ISSOCK(st_m))
		return ('s');
	else
		return ('-');
}

char		*ft_right(mode_t st_m)
{
	char	*buf;

	buf[0] = ft_right2(st_m, &buf);
	buf[1] = st_m & S_IRUSR ? 'r' : buf[1];
	buf[2] = st_m & S_IWUSR ? 'w' : buf[2];
	if ((st_m & S_ISUID) == S_ISUID)
		buf[3] = st_m & S_IXUSR ? 's' : 'S';
	else
		buf[3] = st_m & S_IXUSR ? 'x' : buf[3];
	buf[4] = st_m & S_IRGRP ? 'r' : buf[4];
	buf[5] = st_m & S_IWGRP ? 'w' : buf[5];
	if ((st_m & S_ISGID) == S_ISGID)
		buf[6] = st_m & S_IXGRP ? 's' : 'S';
	else
		buf[6] = st_m & S_IXGRP ? 'x' : buf[6];
	buf[7] = st_m & S_IROTH ? 'r' : buf[7];
	buf[8] = st_m & S_IWOTH ? 'w' : buf[8];
	if ((st_m & S_ISVTX) == S_ISVTX)
		buf[9] = st_m & S_IXOTH ? 't' : 'T';
	else
		buf[9] = st_m & S_IXOTH ? 'x' : buf[9];
	return (buf);
}
