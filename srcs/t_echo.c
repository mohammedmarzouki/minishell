/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_echo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:44 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 15:20:17 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

_Bool	ft_isflag(char *args)
{
	int		i;
	_Bool	n;

	i = 0;
	n = 0;
	if (!(ft_strncmp(args, "-n", 2)))
	{
		i = 2;
		while (args[i] == 'n')
			i++;
	}
	if (!args[i])
		n = 1;
	return (n);
}

void	ft_echo(int i)
{
	int		j;
	int		e;
	_Bool	n;

	j = 1;
	e = how_many_element(g_tool.cmd[i]->args);
	n = 0;
	while (j < e)	// this loop was is here to avoid seg fault in empty echo
	{
		while (ft_isflag(g_tool.cmd[i]->args[j]))
		{
			n = 1;
			j++;
		}
		while (g_tool.cmd[i]->args[j])
		{
			ft_putstr_fd(g_tool.cmd[i]->args[j], 1);
			ft_putstr_fd(" ", 1); // the err of always printing a space at the end even if it is not needed
			j++;
		}
		if (!n)
			ft_putchar_fd('\n', 1);
	}
}
