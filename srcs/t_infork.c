/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_infork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:17:14 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/28 16:17:26 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_infork(int i)
{
	pid_t	pid;

	open_pipe(i);
	pid = fork();
	if (!(g_tool.cmd[i]->sep && *(g_tool.cmd[i]->sep) == '|'))
		waitpid(pid, NULL, 0);
	if (pid == 0)
	{
		set_pipe(i);
		if (!g_tool.cmd[i]->args && g_tool.cmd[i]->red)		//	> file
		{
			if (!(set_redirections(g_tool.cmd[i])))
				exit(g_tool.exterr);
		}
		else if (g_tool.which_builtin)						//	builtin
		{
			if (!(set_redirections(g_tool.cmd[i])))
				exit(g_tool.exterr);
			run_builtin(i);
			exit(g_tool.exterr);
		}
		else
		{
			if (!(set_redirections(g_tool.cmd[i])))
				exit(g_tool.exterr);
			cmd_infork(i);
		}
	}
	close(g_tool.cmd[i]->pipe[1]);
	if (i > 0 && g_tool.cmd[i - 1]->sep && *(g_tool.cmd[i - 1]->sep) == '|')
		close(g_tool.cmd[i - 1]->pipe[0]);
}

void	cmd_infork(int i)
{
	char	*path;
	char	**paths;
	char	*cmd;

	path = getenv("PATH");
	paths = ft_split(path, ':');
	if (ft_strchr(g_tool.cmd[i]->args[0], '/'))
	{
		execve(g_tool.cmd[i]->args[0], g_tool.cmd[i]->args, g_tool.envp);
		printf("minishell: %s: No such file or directory\n", g_tool.cmd[i]->args[0]);
		exit(127);
	}
	else
	{
		cmd = make_cmd(paths, g_tool.cmd[i]->args[0]);
		if (cmd)
			execve(cmd, g_tool.cmd[i]->args, g_tool.envp);
		else
		{
			printf("minishell: %s: command not found\n", g_tool.cmd[i]->args[0]);
			exit(127);
		}
	}
}

char	*make_cmd(char **paths, char *cmd)
{
	int		i;
	char	*temp;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp, cmd);
		if (open(temp, O_RDONLY) > 0)
			return (temp);
		i++;
	}
	return (NULL);
}
