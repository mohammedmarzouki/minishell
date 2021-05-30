/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fin_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 14:56:54 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/05/30 17:45:34 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    fin_slash(char **fin,char *s, int *i)
{
	char hld[2];
	char *hold;
	
	hld[1] = 0;
	(*i)++;
	hold = *fin;
	hld[0] = s[(*i)];
	*fin = ft_strjoin(*fin, hld);
	free(hold);
	(*i)++;
}
void    fin_nrml(char **fin,char *s, int *i)
{
	char hld[2];
	char *hold;
	
	hld[1] = 0;
	hold = *fin;
	hld[0] = s[(*i)];
	*fin = ft_strjoin(*fin, hld);
	free(hold);
	(*i)++;
}
void    fin_sngl_q(char **fin,char *s, int *i)
{	
	(*i)++;
	while(s[(*i)] != '\'')
		fin_nrml(fin, s, i);
	(*i)++;
}
void    fin_vars(char **fin,char *s, int *i)
{
	int j;
	char *var;
	char *hld;
	
	var = ft_strdup("");
	(*i)++;
	while(ft_isalnum(s[(*i)]))
		fin_nrml(&var, s, i);
	j = get_env(var);
	if(j != -1)
	{
		free(var);
		var = *fin;
		hld = ft_getvalue(g_tool.envp[j]);
		*fin = ft_strjoin(var, hld);
		free(hld);
	}
	free(var);
}

void    fin_quote(char **fin,char *s, int *i)
{

	(*i)++;
	while(s[(*i)] != '\"')
	{
		if(s[(*i)] == '\\' && ft_strchr("\\\"$", s[(*i) + 1]))
			fin_slash(fin, s, i);
		else if(s[(*i)] == '\\' && !ft_strchr("\\\"$", s[(*i) + 1]))
		{
			fin_nrml(fin, s, i);
			fin_nrml(fin, s, i);
		}
		else if(s[(*i)] == '$')
			fin_vars(fin, s, i);
		else
			fin_nrml(fin, s, i);
	}
	(*i)++;
}