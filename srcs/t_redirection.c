/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_redirection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:51:06 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/28 18:07:27 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

_Bool	set_redirections(t_cmd *cmd)
{
	int	i;

	i = 0;
	g_tool.fd_in = 0;
	g_tool.fd_out = 0;
	while (cmd->red && cmd->red[i])
	{
		if (!(ft_strcmp(cmd->red[i], ">")))
			g_tool.fd_out = open(cmd->file[i], O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
		else if (!(ft_strcmp(cmd->red[i], ">>")))
			g_tool.fd_out = open(cmd->file[i], O_CREAT | O_APPEND | O_WRONLY, S_IRWXU);
		else
			g_tool.fd_in = open(cmd->file[i], O_RDONLY, S_IRWXU);
		if (g_tool.fd_in < 0 || g_tool.fd_out < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmd->file[i], 2);
			ft_putendl_fd(": No such file or directory", 2);
			return (0);
		}
		if (cmd->red[i + 1] && g_tool.fd_out && cmd->red[i + 1][0] == '>')
			close(g_tool.fd_out);
		else if (cmd->red[i + 1] && g_tool.fd_in && cmd->red[i + 1][0] == '<')
			close(g_tool.fd_in);
		i++;
	}
	if (g_tool.fd_out)
		dup2(g_tool.fd_out, STDOUT_FILENO);
	if (g_tool.fd_in)
		dup2(g_tool.fd_in, STDIN_FILENO);
	return (1);
}

void	reset_std(void)
{
	dup2(g_tool.original_fd_in, STDIN_FILENO);
	dup2(g_tool.original_fd_out, STDOUT_FILENO);
}
