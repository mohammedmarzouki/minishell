/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:48 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 18:14:54 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
**	the cmd is as g_tools.cmd[i]->elm
*/

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	else if (!ft_strcmp(cmd, "cd"))
		return (2);
	else if (!ft_strcmp(cmd, "pwd"))
		return (3);
	else if (!ft_strcmp(cmd, "export"))
		return (4);
	else if (!ft_strcmp(cmd, "unset"))
		return (5);
	else if (!ft_strcmp(cmd, "env"))
		return (6);
	else if (!ft_strcmp(cmd, "exit"))
		return (7);
	else
		return (0);
}

void	executing(void)
{
	int		i;
	_Bool	based_pipe_fork;
	int		which_builtin;

	i = 0;
	while (i < g_tool.cmd_c)
	{
		which_builtin = 0;
		based_pipe_fork = 0;
		if ((g_tool.cmd[i]->sep && *(g_tool.cmd[i]->sep) == '|')
			|| (i > 0 && g_tool.cmd[i - 1]->sep
			&& *(g_tool.cmd[i - 1]->sep) == '|'))
			based_pipe_fork = 1;
		if (g_tool.cmd[i]->args)
			which_builtin = is_builtin(g_tool.cmd[i]->args[0]);
		if (!g_tool.cmd[i]->args && g_tool.cmd[i]->red)		// > file
		{
			if (!(set_redirections(g_tool.cmd[i])))
				return ;
		}
		else if (which_builtin && !based_pipe_fork)			// builtin
		{
			if (!(set_redirections(g_tool.cmd[i])))
				return ;
			run_builtin(i, which_builtin);
		}
		else if (g_tool.cmd[i]->args && !which_builtin)		// others
			printf("\n%d || TO FORK\n", i);
		reset_std();
		i++;
	}
}
