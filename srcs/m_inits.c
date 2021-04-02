/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_inits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:23:04 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/02 15:33:53 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_s_cmd(t_cmd *cmd)
{
	cmd->args = NULL;
	cmd->sep = NULL;
	cmd->red = NULL;
	cmd->file = NULL;
}
