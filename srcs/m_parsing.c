/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:15:36 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/28 11:54:01 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int cmds(char **s)
{
    int c;
    int i;
    int j;

    i = 0;
    c = 0;
    j = 0;
    while (s && s[i])
    {
        if(((s[i][j])) == '|' || (s[i][j]) == ';')
            c++;
        i++;        
    }
    return(c);
}
int seterr(short err)
{
    if (err)
    {
        g_tool.exterr = err;
        return(1);
    }
    return (0);
}
int parsing(char *s)
{
    char    **sp;
    int i;
    while(s && *s == ' ')
        s++;
    if(!(sp = split_it(s, NULL, 0, 0)))
    {
        printf("<%d>\n",g_tool.exterr);
        return(0);
    }
        return(0);
    i = cmds(sp);
    if (seterr(chk_err(sp)))
    {
        printf("<%d>\n",g_tool.exterr);
        return(0);
    }
    printf("<%d>\n",g_tool.exterr);
    assign(sp);
    return (1);
}

// redi
// cmd
// space
// $




//  > w1 > > w2

