/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:19:33 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/26 10:36:51 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int ft_red(char *s)
{
	if(same(s,"<") || same(s,">") ||same(s,">>"))
		return(0);
	return (1);
}

short chk_err(char **sp)
{
	int i;
	int value;
	int flag;

	i = 0;
	flag = 0;
	while(sp && sp[i])
	{
		value = itis(sp[i]);
		if(value == 0)
		{
			flag = 1;
			i++;
			continue;
		}
		else if (value == 1)// < >
		{
			if (!sp[i + 1] || ft_red(sp[i]))
			{
				printf("minishell: syntax error near unexpected token\n");
				return(258);
			}
			else if(itis(sp[i + 1]) != 0)
			{
				printf("minishell: syntax error near unexpected token\n");
				return(258);
				
			}
			else
			{
				flag = 1;
				i += 2;
			}
			continue;
		}
		else if (value == 2)// ;
		{
			if(!flag)
			{
				printf("minishell: syntax error near unexpected token \n");
				return (258);
			}
			else
			{
				flag = 0;
				i++;
				continue;
			}
		}
		else if (value == 3)// |
		{
			if(!flag)   
			{
				printf("minishell: syntax error near unexpected token \n");
				return (258);
			}
			else if(!sp[i + 1])
			{
				printf("minishell: pipe what ?\n");
				return (1);
			}
			else
			{
				flag = 0;
				i++;
				continue;
			}
		}
		else // '\0'
			i++;
	}
	return(0);
}


char **append_line(char **s, char *line, int free)
{
	char **new;
	int i;
	
	i = 0;
	new = malloc(sizeof(char *) * (doublecount(s) + 2));
	while (s && s[i])
	{
		new[i] = ft_strdup(s[i]);
		i++;
	}
	new[i] = ft_strdup(line);
	new[i+1] = NULL;
	if (free)
	{
		doublefree (s);
		nfree (line);
	}
	return (new);
}
