/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_finalize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:46:38 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/05/29 15:09:35 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int    get_env(char *s)
{
    int i;
    char **env;
    char **splt;

    i = -1;
    env = g_tool.envp;
    while(env && env[++i])
    {
        splt = ft_split(env[i], '=');
        if(same(s,splt[0]))
        {
            doublefree(splt);
            return (i);
        }
        doublefree(splt);
    }
    return(-1);
}