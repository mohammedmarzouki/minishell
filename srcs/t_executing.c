/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:48 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/29 16:33:03 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executing(void)
{
	g_tool.i = 0;
	while (g_tool.i < g_tool.cmd_c)
	{
		g_tool.which_builtin = 0;													// *1
		if (g_tool.cmd[g_tool.i]->args)
			is_builtin(g_tool.i);
		if (!g_tool.cmd[g_tool.i]->args && g_tool.cmd[g_tool.i]->red && !based_pipe_fork(g_tool.i))		// > file
		{
			if (!(set_redirections(g_tool.cmd[g_tool.i])))
				return ;
		}
		else if (g_tool.which_builtin && !based_pipe_fork(g_tool.i))						// builtin
			run_builtin(g_tool.i);
		else if (g_tool.cmd[g_tool.i]->args || g_tool.cmd[g_tool.i]->red)							// others
			run_infork(g_tool.i);
		reset_std();
		g_tool.i++;
	}
	while (wait(NULL) > 0)
		;
}
