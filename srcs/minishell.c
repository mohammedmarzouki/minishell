/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:33:25 by tjmari            #+#    #+#             */
/*   Updated: 2021/02/11 12:13:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	*input;

	(void)argc;
	(void)argv;
	(void)env;
	while (1)
	{
		ft_putstr_fd("\033[1;33mminishell$\033[0m ", 1);
		get_next_line(0, &input);
		// parsing();
		// executing();
		free(input);
	}
	return (0);
}
