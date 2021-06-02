/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:03:51 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 11:07:11 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_shlvl(void)
{
	int		i;
	char	**parts;
	char	*temp;
	int		shlvl;

	i = 0;
	while (i < how_many_element(g_tool.envp))
	{
		parts = ft_split(g_tool.envp[i], '=');
		if (!(ft_strcmp(parts[0], "SHLVL")))
		{
			shlvl = ft_atoi(parts[1]);
			shlvl++;
			parts[1] = ft_itoa(shlvl);
			temp = ft_strjoin("", parts[0]);
			temp = ft_strjoin(temp, "=");
			temp = ft_strjoin(temp, parts[1]);
			g_tool.envp[i] = temp;
			return ;
		}
		i++;
		if (!g_tool.envp[i])
		{
			parts = ft_split("export SHLVL=1", ' ');
			g_tool.envp = add_node_dc(g_tool.envp, parts, 2);
			return ;
		}
	}
}

void    unset_oldpwd(void)
{
	int	oldpwd;

	oldpwd = get_env("OLDPWD");
	free(g_tool.envp[oldpwd]);
	g_tool.envp[oldpwd] = ft_strdup("OLDPWD");
}
