/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:15:36 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/16 14:20:28 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void single_q(char *s,int *i)
{
    int f;

    f = 1;
	while(s[(*i)++])
	{
		if(s[(*i)] == '\'')
        {
            f  = 0;
			break;
        }
	}
    if(f)
        printf("parse error : close the quotes !!\n");
}

char    **split_it(char *s)
{
    char **sp;
    int i;
    short flag;
    short 
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
        else if (s[i] == '\'' && !flag) {
			single_q(s,&i);
		}
        else if (s[i] == '"' && flag) {
            flag = 0;
        }
        else if((s[i] == ' ' || s[i] == '|' || s[i] == ';' ) && flag != 1)
        {
            flag = 0;
            sp = append_line(sp,ft_substr(s,start,(i - start)));
			while (s[i] && s[i + 1] == ' ' && s[i] == ' ')
				i++;
            start = i;
		}
        else if((s[i] == '>' || s[i] == '<' ) && !flag)
        {
            flag = 2;
            sp = append_line(sp,ft_substr(s,start,(i - start)));
            start = i;
            while(s[i] == '>' || s[i] == '<')
                i++;
            sp = append_line(sp,ft_substr(s,start,(i - start)));
            start = i;
		}
        if(s[i] == '\\' && s[i+1]) {
            i += 2;
		}
		else
			i++;
    }
	sp = append_line(sp,ft_substr(s,start,(i - start)));
    if(flag == 1)
        printf("parse error : close the quotes !!\n");
    return(sp);
}
int cmds(char **s)
{
    int c;
    int i;
    int j;

    i = 0;
    c = 0;
    while (s && s[i])
    {
        j = 0;
        while((s[i][j]) && (s[i][j]) == ' ')
            j++;
        if(((s[i][j])) == '|' || (s[i][j]) == ';')
            c++;
        i++;        
    }
    return(c);
}
int parsing(char *s)
{
    char    **sp;
    int i;

    sp = split_it(s);
    i = cmds(sp);
    printf("......%d.....\n",chk_err(sp));
    // printf("|||%d|||\n",i);
    assign(sp);
    return (1);
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

