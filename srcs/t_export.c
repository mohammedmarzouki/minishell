/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:52 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 18:27:49 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_export(int i)
{
	char	**temp;
	int		nodes;

	g_tool.exit_status = 0;
	temp = ft_dcdup(g_tool.envp, 0);
	nodes = how_many_nodes(i);
	if (how_many_element(g_tool.cmd[i]->args) == 1)
	{
		sortdcp(temp);
		ft_putexport(temp);
	}
	else
		g_tool.envp = add_node_dc(g_tool.envp, g_tool.cmd[i]->args, nodes);
}

int		how_many_nodes(int i)
{
	int		j;
	int		count;
	char	*temp;

	j = 1;
	count = 0;
	while (j < how_many_element(g_tool.cmd[i]->args))
	{
		if (ft_export_valid(g_tool.cmd[i]->args[j]))
		{
			temp = ft_getkey(g_tool.cmd[i]->args[j]);
			if (get_env(temp) < 0)
				count++;
		}
		else
		{
			ft_putstr_fd("minishell: export: `", 2);
			ft_putstr_fd(g_tool.cmd[i]->args[j], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			g_tool.exit_status = 1;
		}
		j++;
	}
	return (count);
}

char	*ft_getkey(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == '=')
			return (ft_substr(arg, 0, i));
		i++;
	}
	return (arg);
}

char	*ft_getvalue(char *arg)
{
	int	i;

	i = 0;
	if(same(arg,"?"))
		return (ft_itoa(g_tool.exit_status));
	while (arg[i])
	{
		if (arg[i] == '=')
			return (ft_substr(arg, i + 1, ft_strlen(arg)));
		i++;
	}
	return (ft_strdup(""));
}

_Bool	ft_export_valid(char *arg)
{
	arg = ft_getkey(arg);			// may cause a leak
	if (ft_isdigit(arg[0]) || ft_isempty(arg))
		return (0);
	while (*arg)
	{
		if (!ft_isalnum(*arg) && *arg != '_')
			return (0);
		arg++;
	}
	return (1);
}

void	ft_putexport(char **argv)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (argv[i])
	{
		key = ft_getkey(argv[i]);
		value = ft_getvalue(argv[i]);
		if (!ft_strchr(argv[i], '='))
			printf("declare -x %s\n", key);
		else if (ft_strcmp(ft_getvalue(argv[i]), ""))
			printf("declare -x %s=\"%s\"\n", key, value);
		else
			printf("declare -x %s=\"\"\n", key);
		i++;
	}
}
