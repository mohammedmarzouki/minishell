/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:53:53 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/08 14:20:59 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int chk_err(char **sp)
// {
//     return(1);
// }

char **append_line(char **s, char *line)
{
    char **new;
    int i;
    
    i = 0;
    new = malloc(sizeof(char *) * (doublecount(s) + 2));
    while (s && s[i])
    {
        new[i] = ft_strdup(s[i]);
        i++;
    }
    new[i] = ft_strdup(line);
    new[i+1] = NULL;
    doublefree (s);
    nfree (line);
    return (new);
}
