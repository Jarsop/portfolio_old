/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 22:49:58 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/09 18:50:19 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <fcntl.h>
#include <unistd.h>

char	**ft_realloctabstr(char **tab, int size)
{
	char	**realloc;
	int		i;

	i = -1;
	realloc = NULL;
	if (!(realloc = (char**)ft_memalloc(sizeof(char*) * size + 1)))
	{
		ft_putstr_fd("Can't allocate map\n", 2);
		exit(-2);
	}
	if (size == 1)
		return (realloc);
	while (++i < size)
		realloc[i] = tab[i];
	realloc[i] = NULL;
	ft_memdel((void**)&tab);
	return (realloc);
}

int		ft_recuphw(t_w *env, char **map)
{
	char	*space;

	env->map.w = ft_atoi(map[0]);
	if (!(space = ft_strchr(map[0], ' ')))
		return (0);
	env->map.h = ft_atoi(space);
	if (env->map.h < 3 || env->map.w < 3)
		return (0);
	return (1);
}

int		ft_checkmap(t_w *env, char **map)
{
	int		i;

	i = 0;
	if (!ft_recuphw(env, map))
		return (0);
	while (map[++i])
	{
		if (ft_strlen(map[i]) != env->map.w)
			return (0);
	}
	if (--i != env->map.h)
		return (0);
	return (1);
}

char	**ft_openmap(char *name)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	line = NULL;
	map = NULL;
	if ((fd = open(name, O_RDONLY)) < 0)
	{
		ft_putstr_fd("Can't open map\n", 2);
		exit(-1);
	}
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_realloctabstr(map, ++i);
		map[i - 1] = line;
	}
	ft_memdel((void**)&line);
	close(fd);
	return (map);
}
