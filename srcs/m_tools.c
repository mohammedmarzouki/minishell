/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_tools.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:15:30 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/03/05 16:27:07 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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

void	doublefree(char **ptr)
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