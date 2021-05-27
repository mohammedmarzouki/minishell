/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:03:07 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/27 13:33:58 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;

	(void)argc;
	(void)argv;
	g_tool.envp = envp;
	change_shlvl();
	g_tool.original_fd_in = dup(STDIN_FILENO);
	g_tool.original_fd_out = dup(STDOUT_FILENO);
	while (1)
	{
		ft_putstr_fd("\033[0;36mminishell$\033[0m ", 1);
		get_next_line(&input);
		if (!parsing(input))
			printf("No exec\n");
		executing();
		free(input);
	}
	return (0);
}
