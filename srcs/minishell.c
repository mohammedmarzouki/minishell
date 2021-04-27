/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:33:25 by tjmari            #+#    #+#             */
/*   Updated: 2021/04/27 10:52:09 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 

// void	executing(void)
// {
// 	if (getcwd(g_tool.cwd, sizeof(g_tool.cwd)) == NULL)
// 		perror("getcwd() error");
// 	if (ft_strncmp(g_cmd[0].cmd, "echo", 4) == 0)
// 		ft_echo();
// 	else if (ft_strncmp(g_cmd[0].cmd, "cd", 2) == 0)
// 		ft_cd();
// 	else if (ft_strncmp(g_cmd[0].cmd, "pwd", 3) == 0)
// 		ft_pwd();
// 	else if (ft_strncmp(g_cmd[0].cmd, "export", 6) == 0)
// 		ft_export();
// 	else if (ft_strncmp(g_cmd[0].cmd, "env", 3) == 0)
// 		ft_env();
// 	else if (ft_strncmp(g_cmd[0].cmd, "exit", 4) == 0)
// 		ft_exit();
// 	return ;
// }

int		main(int argc, char **argv, char **envp)
{
	char	*input;

	(void)argc;
	(void)argv;
	g_tool.envp = envp;
	while (1)
	{
		ps1();
		get_next_line(0, &input);
		if (!parsing(input))
			printf("no exec\n");
			// executing();
		free(input);
	}
	return (0);
}

// \""
// VAR
// ""