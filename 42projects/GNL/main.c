/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:19:17 by jgeslin           #+#    #+#             */
/*   Updated: 2016/04/01 10:38:38 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"
#include "libft/includes/libft.h"

int		main()
{
	int		fd;
//	int		fd1;
//	int		fd2;
	int		i;
	int		c;
	char	*line;

	//fd = open("get_next_line.c", O_RDONLY);
	//fd = open("cyrus.txt", O_RDONLY);
//	fd1 = open("main.c", O_RDONLY);
//	fd2 = open("get_next_line.h", O_RDONLY);
	fd = 0;
	i = 0;
	c = 0;

	
/*	i = get_next_line(fd, &line);
	ft_putstr(line);
	while ((i = get_next_line(fd1, &line)) != 0)
	{
		c = c + i;
		printf("[%d] %s\n", c, line);
	}
	close(fd1);
	while ((i = get_next_line(fd2, &line)) != 0)
	{
		c = c + i;
		printf("[%d] %s\n", c, line);
	}
	fd1 = open("auteur", O_RDONLY);
	while ((i = get_next_line(fd1, &line)) != 0)
	{
		c = c + i;
		printf("[%d] %s\n", c, line);
	}
	close(fd2);
*/	while ((i = get_next_line(fd, &line)) > 0)
	{
		//c = c + i;
		printf("[%d] %s\n", i, line);
	}
	i = get_next_line(fd, &line);
	printf("[%d] %s\n", i, line);
	close(fd);
/*	close(fd1);
	fd = open("get_next_line.c", O_RDONLY);
	while ((i = get_next_line(fd, &line)) != 0)
	{
		c = c + i;
		printf("[%d] %s\n", c, line);
	}
	close(fd);

*/
//	ft_putnbr(i);
//	i = get_next_line(fd, &line);
//	printf("[%d] %s\n", i, line);
	//free(line);
	//close(fd);
	return (0);
}
