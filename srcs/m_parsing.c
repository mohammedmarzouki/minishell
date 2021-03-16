/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:15:36 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/03/16 17:13:15 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void single_q(char *s,int *i)
{
	while(s[(*i)++])
	{
		if(s[(*i)] == '\'')
			break;
	}
}
char    **split_it(char *s)
{
    char **sp;
    int i;
    short flag;
    int start;

    flag = 0;
    sp = 0;
    start = 0;
	i = 0;
    while (s[i] && *s == ' ')
        s++;
    while (s[i])
    {
        if(s[i] == '"' && !flag) {
            flag = 1;
        }
        else if (s[i] == '\'' && flag) {
			single_q(s,&i);
		}
        else if (s[i] == '"' && flag) {
            flag = 0;
        }
        else if((s[i] == ' ' || s[i] == '|' || s[i] == ';' || s[i] == '>') && !flag)
        {
            sp = append_line(sp,ft_substr(s,start,(i - start)));
            start = i;
			while (s[i] && s[i + 1] == ' ' && s[i] == ' ')
				i++;
		}
        if(s[i] == '\\' && s[i+1]) {
            i += 2;
		}
		else
			i++;
    }
	sp = append_line(sp,ft_substr(s,start,(i - start)));
    return(sp);
}

void parsing(char *s)
{
    char    **sp;

    sp = split_it(s);
    assign(sp);
}

// int     redirection(char *s,int i)
// {
//     if (i == 3)
//     {
//         g_cmd->red = append_line(g_cmd->red,ft_substr(s ,0,2));
//         return(2);
//     }
//     g_cmd->red = append_line(g_cmd->red,ft_substr(s ,0,1));
//     return(1);
// }
// redi
// cmd
// space
// $




//  > w1 > > w2