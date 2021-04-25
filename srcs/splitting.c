/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:40:21 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/25 16:44:24 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void double_q(char *s, int *i)
{
	while(s[++(*i)] && s[(*i)] != '\"')
	{
		if(s[(*i)] == '\\' && s[(*i) + 1])
			(*i) += 2;
	}
}

static void single_q(char *s,int *i)
{
	int f;

	f = 1;
	while(s[(*i)++])
	{
		if(s[(*i)] == '\'')
		{
			f  = 0;
			break;
		}
	}
	if(f)
		printf("parse error : close the quotes !!\n");
}

static  void    write_it(int *i, int *start, char ***sp, char *s)
{
	if((*i) - (*start))
	{
		(*sp) = append_line((*sp),ft_substr(s,(*start),((*i) - (*start))));
		(*start) = (*i);
	}
}

char    **split_it(char *s, char **sp, int i, int start)
{
	while (s[i])
	{
		if(s[i] == '\"')
			double_q(s,&i);
		else if(s[i] == '\'')
			single_q(s, &i);
		else if(s[i] == '\\' && s[i + 1])
			i += 2;
		else if(s[i] == ';' || s[i] == '|')
		{
			write_it(&i, &start, &sp, s);
			i++;
			write_it(&i, &start, &sp, s);
		}
		else if(s[i] == ' ')
		{
			write_it(&i, &start, &sp, s);
			i++;
		}
		else
			i++;
	}
	write_it(&i, &start, &sp, s);
	return (sp);
}