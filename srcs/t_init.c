/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:03:51 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 20:52:19 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_shlvl(void)
{
	int		i;
	int		shlvl;
	char	*temp;
	char	**parts;

	i = ft_getenv("SHLVL");
	if (i < 0)
	{
		parts = ft_dcdup(g_tool.envp, 1);
		parts[how_many_element(g_tool.envp)] = "SHLVL=1";
		doublefree(g_tool.envp);
		g_tool.envp = parts;
		return ;
	}
	shlvl = ft_atoi(ft_getvalue(g_tool.envp[i]));
	free(g_tool.envp[i]);
	temp = ft_strjoin("SHLVL=", ft_itoa(++shlvl));
	g_tool.envp[i] = temp;
}

void	unset_oldpwd(void)
{
	int	oldpwd;

	oldpwd = ft_getenv("OLDPWD");
	free(g_tool.envp[oldpwd]);
	g_tool.envp[oldpwd] = ft_strdup("OLDPWD");
}
