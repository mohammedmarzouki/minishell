/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:36 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/29 20:07:44 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_cd(int i)
{
	if (chdir(g_tool.cmd[i]->args[1]) != 0)
		ft_putendl_fd(strerror(errno), 2);
	return ;
}
