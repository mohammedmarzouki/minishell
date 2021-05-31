/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:47 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/31 10:56:00 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(void)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (g_tool.envp[i])
	{
		key = ft_getkey(g_tool.envp[i]);
		value = ft_getvalue(g_tool.envp[i]);
		if (!ft_strchr(g_tool.envp[i], '='))
			continue ;
		else if (ft_strcmp(ft_getvalue(g_tool.envp[i]), ""))
			printf("%s=%s\n", key, value);
		else
			printf("%s=\n", key);
		i++;
	}
}
