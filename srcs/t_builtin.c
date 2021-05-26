/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_builtin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:06:54 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 13:22:15 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	run_builtin(int i, int which_builtin)
{
	if (which_builtin == 1)
		ft_echo(i);
	else if (which_builtin == 2)
		ft_cd(i);
	else if (which_builtin == 3)
		ft_pwd();
	else if (which_builtin == 4)
		ft_export(i);
	else if (which_builtin == 5)
		ft_unset(i);
	else if (which_builtin == 6)
		ft_env();
	else if (which_builtin == 7)
		ft_exit(i);
}
