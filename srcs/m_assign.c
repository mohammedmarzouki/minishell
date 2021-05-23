/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_assign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:48:56 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/05/01 14:39:23 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static	void	redis(char **sp, int *i, t_cmd	**cmds, int	cmd_i)
{
	cmds[cmd_i]->red = append_line(cmds[cmd_i]->red, sp[(*i)], 0);
	(*i)++;
	cmds[cmd_i]->file = append_line(cmds[cmd_i]->file, sp[(*i)], 0);
}

static void init_cmds(t_cmd	**cmds)
{
	int	i;

	i = 0;
	while (i < g_tool.cmd_c)
	{
		cmds[i] = malloc(sizeof(t_cmd));
		cmds[i]->args = NULL;
		cmds[i]->sep = NULL;
		cmds[i]->red = NULL;
		cmds[i]->file = NULL;
		i++;
	}
}

static	void	next_cmd(char **sp, int i, t_cmd	**cmds, int	*cmd_i)
{
	cmds[(*cmd_i)]->sep = ft_strdup(sp[i]);
	(*cmd_i)++;
}


void	assign(char **sp)
{
	int		i;
	int		j;
	int		cmd_i;
	t_cmd	**cmds;

	cmd_i = 0;
	i = 0;
	j = 0;
	g_tool.cmd_c = (count_cmds(sp) + 1);
	cmds = malloc(sizeof(t_cmd *) * (g_tool.cmd_c + 1)); 
	init_cmds(cmds);
	while (sp[i])
	{
		if(sp[i][j] == '<' || sp[i][j] == '>')
			redis(sp, &i, cmds, cmd_i);
		else if (sp[i][j] == '|' || sp[i][j] == ';')
			next_cmd(sp, i, cmds, &cmd_i);
		else
			cmds[cmd_i]->args = append_line(cmds[cmd_i]->args, sp[i], 0);
		i++;
	}
	g_tool.cmd = cmds;
	doublefree(sp);
}