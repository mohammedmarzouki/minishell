/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:15:36 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/05/01 14:21:16 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int count_cmds(char **s)
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
static void double_print(char **s)
{
    int i = 0;
    if (!s)
    {
        printf("%s\n",NULL);
        return;
    }
    while (s[i])
    {
        printf("[%s]\n",s[i]);
        i++;
    }
    
}
static void printall(void)
{
    int i = 0;

    while (i < g_tool.cmd_c)
    {
        printf("______________args[%d]__________________\n",i);
        double_print(g_tool.cmd[i]->args);
        printf("______________sep[%d]___________________\n",i);
        printf("<%s>\n",g_tool.cmd[i]->sep);
        printf("______________redir[%d]_________________\n",i);
        double_print(g_tool.cmd[i]->red);
        printf("______________File[%d]__________________\n",i);
        double_print(g_tool.cmd[i]->file);
        printf("\n________________________________________\n");
        i++;
    }
    
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
    while(s && *s == ' ')
        s++;
    if(!(sp = split_it(s, NULL, 0, 0)))
    {
        printf("<%d>SPLIT\n",g_tool.exterr);
        return(0);
    }
    if (seterr(chk_err(sp)))
    {
        printf("<%d> sterr\n",g_tool.exterr);
        return(0);
    }
    printf("<%d> TRUE\n",g_tool.exterr);
    assign(sp);
    printall();
    return (1);
}

// redi
// cmd
// space
// $




//  > w1 > > w2

