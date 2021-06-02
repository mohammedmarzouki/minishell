/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_execve_failure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 12:57:23 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 16:17:24 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_regular_file(const char *path)
{
	struct stat path_stat;
	stat(path, &path_stat);
	return S_ISREG(path_stat.st_mode);
}

int	isDirectory(const char *path) {
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
		return 0;
	return S_ISDIR(statbuf.st_mode);
}

int	isExecutable(const char *path) {
	struct stat statbuf;
	if (stat(path, &statbuf) != 0)
		return 0;
	return (statbuf.st_mode & S_IXUSR);
}

void	execve_failure(int i)
{
	char		*path;
	char		*spath;

	path = g_tool.cmd[i]->args[0];
	if (!ft_strchr(path, '/'))
		spath = ft_strjoin("./", path);
	else
		spath = path;
	if (is_regular_file(spath))
	{
		if (!isExecutable(spath))
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(path, 2);
			ft_putendl_fd(": Permission denied", 2);
			exit(126);
		}
		exit(0);
	}
	else if (isDirectory(spath))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": is a directory", 2);
		exit(126);
	}
	else
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(path, 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(127);
	}
}
