/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_executing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 16:06:48 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/28 15:56:08 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	executing(void)
{
	int		i;

	i = 0;
	while (i < g_tool.cmd_c)
	{
		g_tool.which_builtin = 0;													// *1
		if (g_tool.cmd[i]->args)
			is_builtin(i);
		if (!g_tool.cmd[i]->args && g_tool.cmd[i]->red && !based_pipe_fork(i))		// > file
		{
			if (!(set_redirections(g_tool.cmd[i])))
				return ;
		}
		else if (g_tool.which_builtin && !based_pipe_fork(i))						// builtin
			run_builtin(i);
		else if (g_tool.cmd[i]->args || g_tool.cmd[i]->red)							// others
			run_infork(i);
		reset_std();
		i++;
	}
	while (wait(NULL) > 0)
		;
}
