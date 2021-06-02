/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_unset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:58 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/01 17:58:41 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_unset(int i)
{
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	g_tool.exit_status = 0;
	while (g_tool.cmd[i]->args[j])
	{
		if (ft_strchr(g_tool.cmd[i]->args[j], ' ')
			|| ft_strchr(g_tool.cmd[i]->args[j], '=')
			|| ft_isempty(g_tool.cmd[i]->args[j])
			|| !ft_export_valid(g_tool.cmd[i]->args[j]))
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(g_tool.cmd[i]->args[j], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			g_tool.exit_status = 1;
		}
		else
			ft_envremove(g_tool.cmd[i]->args[j]);
		j++;
	}
}

int	ft_isempty(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i])
		return (0);
	return (1);
}

int	ft_envremove(char *var)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(var);
	while (g_tool.envp[i])
	{
		if (!ft_strncmp(g_tool.envp[i], var, len) && g_tool.envp[i][len] == '=')
		{
			j = 0;
			free(g_tool.envp[i]);
			while (g_tool.envp[i + j])
			{
				g_tool.envp[i + j] = g_tool.envp[i + j + 1];
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
