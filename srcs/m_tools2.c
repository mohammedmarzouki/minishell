/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:53:53 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/12 14:47:02 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int chk_err(char **sp)
{
    int i;
    int value;
    int flag;

    i = 0;
    flag = 0;
    while(sp && sp[i])
    {
        value = itis(sp[i]);
        if(value == 0)
        {
            flag = 1;
            i++;
            continue;
        }
        // else if (value == 1)// < >
        // {
        //     if (ft_red(sp , &i) < 0)
        //         return (-1);
        //     // if (!sp[i + 1] || itis(sp[i + 1]) != 0)
        //     // {
        //     //     return(-1);
        //     // }
        //     // else
        //     //     i += 2;
        //     continue;
        // }
        else if (value == 2)// ;
        {
            if(!flag)
                return (-1);
            else
            {
                flag = 0;
                i++;
                continue;
            }
        }
        else if (value == 3)// |
        {
            if(!flag || !sp[i+1])
                return (-1);
            else
            {
                flag = 0;
                i++;
                continue;
            }
        }
        else // '\0'
            i++;
    }
    return(1);
}

int ft_red()
{
    
    return (1);
}

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
