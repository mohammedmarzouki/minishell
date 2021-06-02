/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:50 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/01 19:05:28 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

_Bool	ft_isnumeric(char *arg)
{
	if (arg)
	{
		if (ft_strlen(arg) > 1 && (*arg == '+' || *arg == '-'))
			arg++;
		else if (ft_strlen(arg) == 1)
			return (0);
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

void	ft_printexit(int i)
{
	if (!((g_tool.cmd[i]->sep && *(g_tool.cmd[i]->sep) == '|')
		|| (i > 0 && g_tool.cmd[i - 1]->sep 
		&& *(g_tool.cmd[i - 1]->sep) == '|')))
		ft_putendl_fd("exit", 2);
}

void	ft_exit(int i)
{
	if (how_many_element(g_tool.cmd[i]->args) > 2)
	{
		ft_printexit(i);
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		g_tool.exit_flag = 1;
		g_tool.exit_status = 1;
	}
	else if (ft_isnumeric(g_tool.cmd[i]->args[1]))
	{
		ft_printexit(i);
		if (g_tool.cmd[i]->args[1])
			exit(ft_atoi(g_tool.cmd[i]->args[1]));
		exit(0);
	}
	else
	{
		ft_printexit(i);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(g_tool.cmd[i]->args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
}
