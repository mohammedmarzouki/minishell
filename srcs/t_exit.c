/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:50 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/29 17:39:59 by tjmari           ###   ########.fr       */
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
		if (i > 0 && !(g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|'))
			ft_putendl_fd("exit", 2);
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	else if (ft_isnumeric(g_tool.cmd[i]->args[1]))
	{
		if (i > 0 && !(g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|'))
			ft_putendl_fd("exit", 2);
		if (g_tool.cmd[i]->args[1])
			exit(ft_atoi(g_tool.cmd[i]->args[1]));
		exit(0);
	}
	else
	{
		if (i > 0 && !(g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|'))
			ft_putendl_fd("exit", 2);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(g_tool.cmd[i]->args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	return ;
}
