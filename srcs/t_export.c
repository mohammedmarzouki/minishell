/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:52 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 15:21:35 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_export(int i)
{
	char	**temp;
	int		nodes;

	temp = ft_dcdup(g_tool.envp, 0);
	nodes = how_many_element(g_tool.cmd[i]->args);
	if (nodes == 1)
	{
		sortdcp(temp);
		ft_putexport(temp);
	}
	else
		g_tool.envp = add_node_dc(g_tool.envp, g_tool.cmd[i]->args, nodes);
	return ;
}

void	ft_putexport(char **argv)
{
	int		i;
	char	**parts;

	i = 0;
	while (argv[i])
	{
		parts = ft_split(argv[i++], '=');
		printf("declare -x %s=\"%s\"\n", parts[0], parts[1]);
	}
}
