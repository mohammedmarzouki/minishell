/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_finalize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:46:38 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/05/30 09:13:38 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		get_env(char *s)
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

// '\' -> '$' ->'\"'
// char	*fin_line(char	*s)
// {
// 	int	i;
// 	int flag;

// 	i = 0;
// 	flag = 0;
// 	while(s[i])
// 	{
// 		if(s[i] == '\\' &&!flag)
// 		{
			
// 		}
// 	}
// }

// void	fin_lines(char	**strs)
// {
// 	char	*s;
// 	int		inc;
	
// 	inc = -1;
// 	while(strs[++inc])
// 	{
// 		s = fin_line(strs[inc]);
// 		free(strs[inc]);
// 		strs[inc] = s;
// 	}
// }

// void	finalizem(int	i)
// {
// 	while (g_tool.cmd[i]->args || g_tool.cmd[i]->file)
// 	{
// 		if(g_tool.cmd[i]->args)
// 			break;
// 			// fin_lines(g_tool.cmd[i]->args);
// 		if(g_tool.cmd[i]->file)
// 			break;
// 			// fin_lines(g_tool.cmd[i]->file);
// 		if(same(g_tool.cmd[i]->sep, NULL) || same(g_tool.cmd[i]->sep,";"))
// 			break;
// 		else
// 			i++;
// 	}
// }