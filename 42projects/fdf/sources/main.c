/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 15:45:33 by jgeslin           #+#    #+#             */
/*   Updated: 2016/03/09 11:16:58 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_hex(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			break ;
		++i;
	}
	return (ft_strsub(line, 0, i));
}

void	ft_puterror(int error)
{
	if (error == 1)
		ft_putendl("Error in file");
	if (error == 2)
		ft_putendl("No such file to work fdf");
	exit(0);
}

int		ft_open(char *av)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) <= 0)
		ft_puterror(2);
	return (fd);
}

void	ft_freemap(t_mlx *mlx)
{
	int		x;
	int		y;

	y = mlx->y_max;
	while (y--)
		free(mlx->map[y]);
	free(mlx->map);
}

int		main(int ac, char **av)
{
	t_map	**map;
	int		xy[3];

	if (ac != 2)
	{
		ft_putendl("Invalid argument number !");
		return (0);
	}
	xy[0] = 0;
	xy[1] = 0;
	xy[2] = 0;
	map = ft_parse(av[1], xy);
	if (map)
		ft_mlx(map, av[1]);
	return (0);
}
