/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:53:53 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/03/16 16:13:22 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int     is_red(char *s)
// {
//     // < 1
//     // > 2
//     // >> 3
//     if(*s == '<')
//         return(1);
//     else if (*s == '>')
//     {
//         if(s[1] != '>')
//             return(2);
//         else 
//             return (3);
//     }
//     return (0);
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

int     a_word(char *s)
{
    int i;

    i = 0;
    while(s[i] && s[i] == ' ')
        i++;
    while (s[i] && s[i] != ' ')
        i++;
    return(i);
}