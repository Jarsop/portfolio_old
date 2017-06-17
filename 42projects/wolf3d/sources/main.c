/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:57:51 by jgeslin           #+#    #+#             */
/*   Updated: 2016/12/14 11:43:37 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>
#include <SDL.h>
#include <SDL_mixer.h>

int		ft_quit(t_w *e)
{
	exit(0);
	return (1);
}

int		ft_mouse(int x, int y, t_w *e)
{
	if (x > WIN_X / 2 + 150)
		ft_turn(e, 1);
	else if (x < WIN_X / 2 - 150)
		ft_turn(e, 0);
	return (1);
}

int		**ft_convertmap(char **map, int h, int w)
{
	int		**ret;
	int		i;
	int		l;

	i = -1;
	if (!(ret = (int**)malloc(sizeof(int*) * h)))
		exit(-1);
	while (++i < h)
	{
		if (!(ret[i] = (int*)malloc(sizeof(int) * w)))
			exit(-1);
		l = -1;
		while (++l < w)
			ret[i][l] = map[i + 1][l] - 48;
	}
	return (ret);
}

void	ft_map(t_w *env, char *name)
{
	char	**map;

	map = ft_openmap(name);
	if (!ft_checkmap(env, map))
	{
		ft_putstr_fd("Bad map\n", 2);
		exit(-3);
	}
	env->map.map = ft_convertmap(map, env->map.h, env->map.w);
	ft_freestab(map);
	if (!ft_strcmp(name, "./maps/map2"))
		ft_init(env);
}

int		main(void)
{
	t_w			env;
	Mix_Music	*son;

	ft_map(&env, "./maps/map");
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		ft_printf("%s", Mix_GetError());
	son = Mix_LoadMUS("./music/son.mp3");
	Mix_PlayMusic(son, -1);
	ft_start_game(&env);
	return (0);
}
