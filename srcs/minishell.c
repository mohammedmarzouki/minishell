/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:33:25 by tjmari            #+#    #+#             */
/*   Updated: 2021/04/28 11:49:23 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		g_tool.exterr = 0;//to be removed
		if (!parsing(input))
			printf("no exec\n");
		executing();
		free(input);
	}
	return (0);
}
