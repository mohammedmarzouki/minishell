/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:33:51 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/27 11:14:01 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

_Bool	based_pipe_fork(int i)
{
	if ((g_tool.cmd[i]->sep && *(g_tool.cmd[i]->sep) == '|')
		|| (i > 0 && g_tool.cmd[i - 1]->sep
		&& *(g_tool.cmd[i - 1]->sep) == '|'))
		return (1);
	return (0);
}
