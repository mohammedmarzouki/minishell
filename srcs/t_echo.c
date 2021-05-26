/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 20:12:44 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 11:18:28 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

_Bool	ft_isflag(char *args)
{
	int	i;
	_Bool	n;

	i = 0;
	n = 0;
	if (!(ft_strncmp(args, "-n", 2)))
	{
		i = 2;
		while (args[i] == 'n')
			i++;
	}
	if (!args[i])
		n = 1;
	return (n);
}

void	ft_echo(int i)
{
	int		j;
	_Bool	n;

	j = 1;
	n = 0;
	while (ft_isflag(g_tool.cmd[i]->args[j]))
	{
		n = 1;
		j++;
	}
	while (g_tool.cmd[i]->args[j])
    {
		ft_putstr_fd(g_tool.cmd[i]->args[j], 1);
        ft_putstr_fd(" ", 1); // the err of always printing a space at the end even if it is not needed
        j++;    
    }
	if (!n)
		ft_putchar_fd('\n', 1);
}
