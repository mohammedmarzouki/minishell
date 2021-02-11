/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_inits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:23:04 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/02/11 12:14:48 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    init_s_cmd(void)
{
    int     i;

    i = 0;
    
    while(i < g_tool.cmd_i)
    {
        g_cmd[i].cmd = ft_strdup("");
        g_cmd[i].flg = ft_strdup("");
        g_cmd[i].sep = ft_strdup("");
        g_cmd[i].args = ft_strdup("");
        i++;
    }
}