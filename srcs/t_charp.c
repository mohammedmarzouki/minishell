/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_charp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:20:31 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 11:04:12 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	how_many_element(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

char	**ft_dcdup(char **argv, int toadd)
{
	int		i;
	int		len;
	char	**temp;

	i = 0;
	len = how_many_element(argv);
	temp = (char **)malloc(sizeof(char *) * (len + toadd + 1));
	temp[len + toadd] = NULL;
	while (i < len)
	{
		temp[i] = ft_strdup(argv[i]);
		i++;
	}
	return (temp);
}

char	**sortdcp(char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) < 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (argv);
}

char	**add_node_dc(char **argv, char **args, int to_add)
{
	int	envp_len;
	int	envp_len_h;
	int	i;

	envp_len = how_many_element(argv);
	envp_len_h = envp_len;
	i = 1;
	argv = ft_dcdup(argv, to_add);
	while ((envp_len < envp_len_h + (how_many_element(g_tool.cmd[g_tool.i]->args) - 1)) && args[i])
	{
		
		if (ft_export_valid(args[i]) && get_env(ft_getkey(args[i])) < 0)
			argv[envp_len++] = ft_strdup(args[i]);
		else if (ft_export_valid(args[i]) && get_env(ft_getkey(args[i])) >= 0)
			argv = change_envp_var(argv, get_env(ft_getkey(args[i])), args[i]);
		i++;
	}
	return (argv);
}

char	**change_envp_var(char **argv, int index, char *arg)
{
	free(argv[index]);
	argv[index] = ft_strdup(arg);
	return (argv);
}
