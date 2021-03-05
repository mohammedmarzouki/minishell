/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:15:36 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/03/05 16:26:32 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void parsing(char *s)
{
    int i;

    i = 0;
    while(*s == ' ')
        s++;
    while(*s) 
    {
        i = is_red(s);
        if (i)
            s += redirection(s,i);
        
        s++;
    }

}

int     redirection(char *s,int i)
{
    if (i == 3)
    {
        
    }
}
// redi
// cmd
// space
// $




//  > w1 > > w2