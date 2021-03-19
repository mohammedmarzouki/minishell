/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_assign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:48:56 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/03/19 16:27:27 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// void	check_redi(char **sp, int *i)
// {
// 	int		j;

// 	j = 0;
// 	while (sp[*i][j])
// 	{
// 		if (sp[*i][j] == '>' && sp[(*i)++][j] == '>')
// 			append_in();
// 		else if (sp[*i][j] == '>')
// 			put_in();
// 		else if (sp[*i][j] == '<')
// 			take_from();
// 	}
// }

// void	check_args(char **sp)
// {
	
// }

void	assign(char **sp)
{
	int		i;
	// int		j;
	
	i = 0;
	while (sp[i])
	{
		// j = 0;
		// while (sp[i][j] == ' ')
		// 	j++;
		// if(sp[i][j] == '<' || sp[i][j] == '>')
		// 	check_redi(sp, &i);
		// else
		// 	check_args(sp);
		printf("|%s|\n", sp[i]);
		i++;
	}
}