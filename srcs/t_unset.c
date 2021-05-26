/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:58 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 11:37:40 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(int i)
{
	int	j;
	int	j2;
	int	nodes;
	int	toalloc;
	char	**temp;

	j = 0;
	j2 = 0;
	nodes = how_many_element(g_tool.cmd[i]->args);
	toalloc = (how_many_element(g_tool.envp) + 1) - (nodes - 1);
	temp = (char **)malloc(sizeof(char *) * toalloc);
	temp[toalloc - 1] = NULL;
	while (j < how_many_element(g_tool.envp))
	{
		if (ft_isin(g_tool.envp[j], g_tool.cmd[j]->args))
			j++;
		else
			temp[j2++] = g_tool.envp[j++];
	}
	g_tool.envp = temp;
	return ;
}

_Bool	ft_isin(char *node, char **argv)
{
	int	i;
	char	**parts;

	i = 0;
	while (argv[i])
	{
		parts = ft_split(node, '=');
		if (!(ft_strcmp(parts[0], argv[i])))
			return (1);
		i++;
	}
	return (0);
}
