/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_what_way.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:06:54 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 18:56:18 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_builtin(int i, int which_builtin)
{
	if (!(set_redirections(g_tool.cmd[i])))
		return ;
	if (which_builtin == 1)
		ft_echo(i);
	else if (which_builtin == 2)
		ft_cd(i);
	else if (which_builtin == 3)
		ft_pwd();
	else if (which_builtin == 4)
		ft_export(i);
	else if (which_builtin == 5)
		ft_unset(i);
	else if (which_builtin == 6)
		ft_env();
	else if (which_builtin == 7)
		ft_exit(i);
}

void	run_execution(int i)
{
	char	*path;
	char	**paths;
	char	*cmd;
	pid_t	pid;

	path = getenv("PATH");
	paths = ft_split(path, ':');
	if (ft_strchr(g_tool.cmd[i]->args[0], '/'))
	{
		pid = fork();
		wait(NULL);
		if (pid == 0)
		{
			execve(g_tool.cmd[i]->args[0], g_tool.cmd[i]->args, g_tool.envp);
			printf("minishell: %s: No such file or directory\n", g_tool.cmd[i]->args[0]);
			exit(127);
		}
	}
	else
	{
		cmd = make_cmd(paths, g_tool.cmd[i]->args[0]);
		if (cmd)
		{
			pid = fork();
			wait(NULL);
			if (pid == 0)
				execve(cmd, g_tool.cmd[i]->args, g_tool.envp);
		}
		else
			printf("minishell: %s: command not found\n", g_tool.cmd[i]->args[0]);
	}
	return ;
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
