/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:50 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/28 13:09:50 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

_Bool	ft_isnumeric(char *arg)
{
	if (arg)
	{		
		while (*arg)
		{
			if (*arg >= '0' && *arg <= '9')
				arg++;
			else if (*arg == '\0')
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

void	ft_exit(int i)
{
	if (how_many_element(g_tool.cmd[i]->args) > 2)
	{
		if (!(g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|'))
			ft_putendl_fd("exit", 1);
		ft_putendl_fd("minishell: exit: too many arguments", 1);
	}
	else if (ft_isnumeric(g_tool.cmd[i]->args[1]))
	{
		if (!(g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|'))
			ft_putendl_fd("exit", 1);
		if (g_tool.cmd[i]->args[1])
			exit(ft_atoi(g_tool.cmd[i]->args[1]));
		exit(0);
	}
	else
	{
		if (!(g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|'))
			ft_putendl_fd("exit", 1);
		printf("minishell: exit: %s: numeric argument required\n", g_tool.cmd[i]->args[1]);
		exit(255);
	}
	return ;
}
