/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_assign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:48:56 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/03/30 10:55:59 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redis(char **sp, int *i)
{
	int		j;

	j = 0;
	while (sp[*i][j] && (sp[*i][j] == '<' || sp[*i][j] == '>'))
		j++;
	
}

// void	check_args(char **sp)
// {
	
// }

void	assign(char **sp)
{
	int		i;
	int		j;
	
	i = 0;
	while (sp[i])
	{
		j = 0;
		while (sp[i][j] == ' ')
			j++;
		if(sp[i][j] == '<' || sp[i][j] == '>')
			redis(sp, &i);
		else
			add_args(sp);
		printf("|%s|\n", sp[i]);
		i++;
	}
}