/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:03:07 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/04 17:00:17 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	initials(void)
{
	t_trm	*trm;

	change_shlvl();
	unset_oldpwd();
	g_tool.original_fd_in = dup(STDIN_FILENO);
	g_tool.original_fd_out = dup(STDOUT_FILENO);
	signal(SIGINT, signal_int);
	signal(SIGQUIT, signal_quit);
	tgetent(NULL,getenv("TERM"));
	trm = malloc(sizeof(t_trm));
	trm->curr = ft_strdup("");
	trm->last = NULL;
	trm->line = NULL;
	trm->lni = 0;
	g_tool.trm = trm;
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*input;
	
	(void)argc;
	(void)argv;
	g_tool.envp = ft_dcdup(envp, 0);
	initials();
	while (1)
	{
		g_tool.pid = 0;
		g_tool.exit_flag = 0;
		ft_putstr_fd("\033[0;36mminishell$\033[0m ", 1);
		term_line(&input, 0);
		// get_next_line(&input);
		if (parsing(input))
			executing();
		free(input);
	}
	return (0);
}
