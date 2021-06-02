/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:36 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 20:36:02 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_pwd(int index, char *arg)
{
	free(g_tool.envp[index]);
	g_tool.envp[index] = ft_strdup(arg);
}

void	ft_cd(int i)
{
	g_tool.exit_status = 0;
	int pwd = ft_getenv("PWD");
	int oldpwd = ft_getenv("OLDPWD");
	if (how_many_element(g_tool.cmd[i]->args) == 1)
	{
		ft_putendl_fd("cd with only a relative or absolute path", 2);
		g_tool.exit_status = 1;
	}
	else if (chdir(g_tool.cmd[i]->args[1]) != 0)
	{
		if (ft_strcmp(g_tool.cmd[i]->args[1], ""))
		{
			ft_putstr_fd("minishell: cd: ", 2);
			ft_putstr_fd(g_tool.cmd[i]->args[1], 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
		}
		g_tool.exit_status = 1;
	}
	else
	{
		if (oldpwd >= 0 && pwd >= 0)
			change_pwd(oldpwd, ft_strjoin("OLDPWD=", ft_getvalue(g_tool.envp[pwd])));
		if (pwd >= 0)
		{
			if (getcwd(g_tool.cwd, sizeof(g_tool.cwd)))
				change_pwd(pwd, ft_strjoin("PWD=", g_tool.cwd));
			else
			{	
				ft_putstr_fd("cd: error retrieving current directory: ", 2);
				ft_putstr_fd("getcwd: cannot access parent directories:", 2);
				ft_putendl_fd(" No such file or directory", 2);
				change_pwd(pwd, ft_strjoin(g_tool.envp[pwd], ft_strjoin("/", g_tool.cmd[i]->args[1])));
			}
		}
	}
}
