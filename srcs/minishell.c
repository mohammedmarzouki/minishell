/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:33:25 by tjmari            #+#    #+#             */
/*   Updated: 2021/02/10 14:32:24 by tjmari           ###   ########.fr       */
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
		ft_putendl_fd(input, 1);
		free(input);
	}
	return (0);
}
