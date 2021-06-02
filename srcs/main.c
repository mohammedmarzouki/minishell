/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:03:07 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 11:02:15 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	
	(void)argc;
	(void)argv;
	g_tool.envp = ft_dcdup(envp, 0);
	change_shlvl();
	unset_oldpwd();
	g_tool.original_fd_in = dup(STDIN_FILENO);
	g_tool.original_fd_out = dup(STDOUT_FILENO);
	signal(SIGINT, signal_int);
	signal(SIGQUIT, signal_quit);
	while (1)
	{
		g_tool.pid = 0;
		g_tool.exit_flag = 0;
		ft_putstr_fd("\033[0;36mminishell$\033[0m ", 1);
		get_next_line(&input);
		if (parsing(input))
			executing();
		free(input);
	}
	return (0);
}
