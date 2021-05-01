/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:40:21 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/05/01 14:25:28 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int double_q(char *s, int *i)
{
	int f;

	f = 1;
	while(s[++(*i)])
	{
		if(s[(*i)] == '\\' && s[(*i) + 1])
			(*i) += 2;
		else if (s[(*i)] == '\"')
		{
			f = 0;
			++(*i);
			break;
		}
	}
	if(f)
	{
		printf("parse error : close the quotes !!\n");
		return (seterr(1));
	}
	return (0);
}

static int single_q(char *s,int *i)
{
	int f;

	f = 1;
	while(s[++(*i)])
	{
		if(s[(*i)] == '\'')
		{
			f  = 0;
			++(*i);
			break;
		}
	}
	if(f)
	{	
		printf("parse error : close the quotes !!\n");
		return (seterr(1));
	}
	return (0);
}

static  void    write_it(int *i, int *start, char ***sp, char *s)
{
	if((*i) - (*start))
	{
		(*sp) = append_line((*sp),ft_substr(s,(*start),((*i) - (*start))));
		(*start) = (*i);
	}
}
static void redir(int *i, int *start, char ***sp, char *s)
{
	write_it(i, start, sp, s);
	while(s[(*i)] == '>' || s[(*i)] == '<')
		(*i)++;
	write_it(i, start, sp, s);
}
static void shorten(int *i, int *start, char ***sp, char *s)
{
	write_it(i, start, sp, s);
	(*i)++;
	write_it(i, start, sp, s);
}
char    **split_it(char *s, char **sp, int i, int start)
{
	while (s[i])
	{
		if(s[i] == '\"' && double_q(s,&i))
			return (doublefree(sp));
		else if(s[i] == '\'' && single_q(s, &i))
			return (doublefree(sp));
		else if(s[i] == '\\' && s[i + 1])
			i += 2;
		else if(s[i] == ';' || s[i] == '|')
			shorten(&i, &start, &sp, s);
		else if(s[i] == ' ')
		{
			write_it(&i, &start, &sp, s);
			i++;
			start =  i;
		}
		else if(s[i] == '>' || s[i] == '<')
			redir(&i, &start, &sp, s);
		else
			i++;
	}
	write_it(&i, &start, &sp, s);
	return (sp);
}