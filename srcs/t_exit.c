/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:50 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 11:27:56 by tjmari           ###   ########.fr       */
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
	if (ft_isnumeric(g_tool.cmd[i]->args[1]))
	{
		ft_putendl_fd("exit", 1);
		if (g_tool.cmd[i]->args[1])
			exit(ft_atoi(g_tool.cmd[i]->args[1]));
		exit(0);
	}
	else
	{
		ft_putendl_fd("exit", 1);
		printf("minishell: exit: %s: numeric argument required\n", g_tool.cmd[i]->args[1]);
		exit(255);
	}
	return ;
}
