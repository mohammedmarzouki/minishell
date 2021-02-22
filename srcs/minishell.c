/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:33:25 by tjmari            #+#    #+#             */
/*   Updated: 2021/02/22 12:02:01 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tj_cmd(void)
{
	g_cmd[0].cmd = "exit";
	g_cmd[0].args = "15";
	g_cmd[0].sep = NULL;
	g_cmd[0].red = NULL;
	g_cmd[0].file = NULL;
}

void	executing(void)
{
	if (getcwd(g_tool.cwd, sizeof(g_tool.cwd)) == NULL)
		perror("getcwd() error");
	if (ft_strncmp(g_cmd[0].cmd, "echo", 4) == 0)
		ft_echo();
	else if (ft_strncmp(g_cmd[0].cmd, "cd", 2) == 0)
		ft_cd();
	else if (ft_strncmp(g_cmd[0].cmd, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(g_cmd[0].cmd, "export", 6) == 0)
		ft_export();
	else if (ft_strncmp(g_cmd[0].cmd, "env", 3) == 0)
		ft_env();
	else if (ft_strncmp(g_cmd[0].cmd, "exit", 4) == 0)
		ft_exit();
	return ;
}

int		main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	g_tool.envp = envp;
	// tj_cmd();
	while (1)
	{
		ps1();
		get_next_line(0, &input);
		parsing(input);
		// executing();
		free(input);
	}
	return (0);
}
