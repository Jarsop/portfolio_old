/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 17:10:36 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/10 15:23:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_cntspace(char *line)
{
	int		cnt;

	cnt = 0;
	if (line && *line)
	{
		while (*line == ' ')
			++line;
		while (*line)
		{
			if (*line == ' ' && *(line + 1))
			{
				while (*line == ' ')
					++line;
				if (*line + 1)
					++cnt;
			}
			++line;
		}
	}
	return (cnt + 1);
}

void	ft_firstparse(int fd, int *xy)
{
	char	*line;
	int		f;

	f = 0;
	while (get_next_line(fd, &line) > 0)
	{
		f = 1;
		xy[0] = ft_cntspace(line);
		if (line)
			ft_memdel((void**)&line);
		if (xy[1] && xy[1] != xy[0])
			ft_puterror(1);
		xy[1] = xy[0];
		++xy[2];
	}
	if (!f)
		exit(0);
	if (line)
		ft_memdel((void**)&line);
}

void	ft_recup(t_map *map, char *line)
{
	int		i;
	int		l;
	char	*hex;

	i = 0;
	l = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			++i;
		map[l].z = ft_atoi(&line[i++]);
		map[l].color = -1;
		while (line[i] && line[i] != ' ')
		{
			if (line[i] == ',')
			{
				hex = ft_hex(&line[i + 3]);
				map[l].color = ft_atoi_base(hex, "0123456789ABCDEF");
				if (hex)
					ft_memdel((void**)&hex);
			}
			++i;
		}
		++l;
	}
}

t_map	**ft_realparse(int fd, int *xy)
{
	t_map	**map;
	char	*line;
	int		y;
	int		i;

	y = -1;
	i = 0;
	if (!(map = (t_map**)ft_memalloc(sizeof(t_map*) * xy[2])))
		return (NULL);
	while (++y < xy[2])
		if (!(map[y] = (t_map*)ft_memalloc(sizeof(t_map) * xy[0])))
			return (NULL);
	map[0][0].x = xy[0];
	map[0][0].y = xy[2];
	while (get_next_line(fd, &line) > 0)
	{
		ft_recup(map[i], line);
		if (line)
			ft_memdel((void**)&line);
		++i;
	}
	if (line)
		ft_memdel((void**)&line);
	return (map);
}

t_map	**ft_parse(char *av, int *xy)
{
	t_map	**map;
	int		fd;

	fd = ft_open(av);
	ft_firstparse(fd, xy);
	close(fd);
	fd = ft_open(av);
	map = ft_realparse(fd, xy);
	close(fd);
	return (map);
}
