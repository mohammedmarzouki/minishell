/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:15:30 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/04/27 10:48:41 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		itis(char *s) 
{
	int i;

	i = 0;
	while(s[i] && s[i] == ' ')
		i++;
	if (s[i] == '<' || s[i] == '>')
		return (1);
	else if (s[i] == ';')
		return (2);
	else if (s[i] == '|')
		return (3);
	else if(!s[i])
		return (-1);
	else
		return (0);
}

void    ft_crop(char *src ,char **des ,int start ,int len)
{
    nfree(*des);
    *des = ft_substr(src ,start ,len);
}

void    nfree(void *s)
{
    if(s)
    {
        free (s);
        s = NULL;
    }
}

int		same(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (*s1)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	return (1);
}

char	**doublefree(char **ptr)
{
	int i;

	if (ptr != NULL)
	{
		i = doublecount(ptr);
		while (i >= 0)
		{
			free(ptr[i]);
			i--;
		}
		free(ptr);
	}
	ptr = NULL;
	return (NULL);
}

int		doublecount(char **s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}