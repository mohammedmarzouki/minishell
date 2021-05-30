/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:19:33 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/30 10:40:30 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int ft_red(char *s)
{
	if(same(s,"<") || same(s,">") ||same(s,">>"))
		return(0);
	return (1);
}

int backslash(char *s)
{
	int i;
	
	i = 0;
	while (s && s[i])
	{
		if(s[i] == '\\' && !s[i + 1])
		{
			ft_putstr_fd("minishell: multiline commands are not supported \n"
			, 2);
			return (1);
		}
		if(s[i] == '\\' && s[i + 1])
			i++;
		i++;
	}
	return (0);
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
		if(backslash(sp[i]))
			return(1);
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
				ft_putstr_fd("minishell: syntax error \n", 2);
				return(258);
			}
			if(itis(sp[i + 1]) != 0)
			{
				ft_putstr_fd("minishell: syntax error \n",2);
				return(258);
				
			}
			if(backslash(sp[i + 1]))
				return(1);
				flag = 1;
				i += 2;
			continue;
		}
		else if (value == 2)// ;
		{
			if(!flag)
			{
				ft_putstr_fd("minishell: syntax error  \n",2);
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
				ft_putstr_fd("minishell: syntax error  \n",2);
				return (258);
			}
			else if(!sp[i + 1])
			{
				ft_putstr_fd("minishell: pipe what ?\n",2);
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
