/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:52 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/31 10:26:40 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_export(int i)
{
	char	**temp;
	int		nodes;

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
		}
		j++;
	}
	return (count);
}

_Bool	ft_strset(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(set, s[i]))
			return (1);
		i++;
	}
	return (0);
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
	if (ft_isdigit(arg[0]) || ft_strset(arg, " !\"#$%&'+,-./:;?@[\\]^{|}~")
		|| ft_isempty(arg))
		return (0);
	return (1);
}

void	ft_putexport(char **argv)
{
	int		i;
	char	**parts;

	i = 0;
	while (argv[i])
	{
		parts = ft_split(argv[i++], '=');
		if (parts[1])
			printf("declare -x %s=\"%s\"\n", parts[0], parts[1]);
		else
			printf("declare -x %s=\"\"\n", parts[0]);
	}
}
