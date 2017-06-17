/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <jgeslin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 10:28:37 by jgeslin           #+#    #+#             */
/*   Updated: 2016/05/26 16:49:55 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_cntandor(char *buf, char c)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (buf[++i])
	{
		if (buf[i] == c)
			++nb;
	}
	if (nb && ft_ispaire(nb))
		return (nb);
	else if (nb)
	{
		ft_error("Minishell: parse error near `&' or `|'\n");
		return (-1);
	}
	else
		return (0);
}

void	ft_and(t_shell *shell, char *buf, int and)
{
	char	**taba;
	int		i;

	i = -1;
	taba = NULL;
	taba = ft_strsplit(buf, '&');
	taba = ft_cleantabspace(taba);
	while (taba[++i])
	{
		shell->ret = 1;
		shell->av = ft_strsplit(taba[i], ' ');
		shell->av = ft_cleantabspace(shell->av);
		if (!ft_chkbuiltin(shell, shell->av[0]))
			shell->ret = ft_exec(shell, 0);
		if (shell->av && shell->av[0])
			ft_freestab(shell->av);
		if (shell->ret)
			break ;
		shell->ret = 0;
	}
	if (taba && taba[0])
		ft_freestab(taba);
}

void	ft_or(t_shell *shell, char *buf, int or)
{
	char	**tabo;
	int		i;

	i = -1;
	tabo = NULL;
	tabo = ft_strsplit(buf, '|');
	tabo = ft_cleantabspace(tabo);
	while (tabo[++i])
	{
		shell->ret = 0;
		shell->av = ft_strsplit(tabo[i], ' ');
		shell->av = ft_cleantabspace(shell->av);
		if (!ft_chkbuiltin(shell, shell->av[0]))
			shell->ret = ft_exec(shell, 0);
		if (shell->av && shell->av[0])
			ft_freestab(shell->av);
		if (!shell->ret)
			break ;
		shell->ret = 0;
	}
	if (tabo && tabo[0])
		ft_freestab(tabo);
}

int		ft_checkandor(t_shell *shell, char *buf)
{
	int		a;
	int		or;

	a = 0;
	or = 0;
	if ((a = ft_cntandor(buf, '&')) > 0 && ft_strstr(buf, "&&"))
		ft_and(shell, buf, a);
	if ((or = ft_cntandor(buf, '|')) > 0 && ft_strstr(buf, "||"))
		ft_or(shell, buf, or);
	return (a || or ? 1 : 0);
}
