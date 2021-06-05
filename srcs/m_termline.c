/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_termline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:21:30 by mmarzouk          #+#    #+#             */
/*   Updated: 2021/06/05 12:16:03 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	printchr(int c)
{
	write(1,&c,sizeof(int));
	return(c);
}
static int read_chr(void)
{
	struct	termios	term;
	struct	termios	init;
	int				chr;

	chr = 0;
	tcgetattr(0, &term);
	tcgetattr(0, &init);
	term.c_lflag = ~(ICANON | ECHO);
	term.c_cc[VTIME] = 0;
	term.c_cc[VMIN] = 1;
	tcsetattr(0,TCSANOW, &term);
	if(read(0, &chr, 4) < 0)
		chr = -1;
	tcsetattr(0,TCSANOW, &init);
	return (chr);
}
static	void	del(void)
{
	char *tmp;
	
	tmp = g_tool.trm->curr;
	g_tool.trm->curr = ft_substr(tmp,0,ft_strlen(tmp) - 1);
	g_tool.trm->h_cur = tgetstr("le",NULL);
	ft_putstr_fd(g_tool.trm->h_cur, 1);
	g_tool.trm->h_cur = tgetstr("cd",NULL);
	ft_putstr_fd(g_tool.trm->h_cur, 1);
	free (tmp);
}

static	void	up(int *i)
{
	if((*i) == 0 || !doublecount(g_tool.trm->line))
		return;
	(*i)--;
	if((*i) == (doublecount(g_tool.trm->line) - 1))
		g_tool.trm->last = ft_strdup(g_tool.trm->curr);
	free(g_tool.trm->curr);
	g_tool.trm->curr = ft_strdup(g_tool.trm->line[(*i)]);
}

static	void	down(int *i)
{
	if((*i) == doublecount(g_tool.trm->line) || !doublecount(g_tool.trm->line))
		return;
	if((*i) == ((doublecount(g_tool.trm->line) - 1)) && g_tool.trm->last)
	{
		free(g_tool.trm->curr);
		g_tool.trm->curr = ft_strdup(g_tool.trm->last);
		(*i)++;
		free(g_tool.trm->last);
		g_tool.trm->last = NULL;
		return;
	}
	(*i)++;
	free(g_tool.trm->curr);
	g_tool.trm->curr = ft_strdup(g_tool.trm->line[(*i)]);
	
}

static	void	new_line(char **line)
{
	*line = ft_strdup(g_tool.trm->curr);
	if(g_tool.trm->curr && g_tool.trm->curr[0])
	{
		g_tool.trm->line = append_line(g_tool.trm->line, g_tool.trm->curr, 1);
		g_tool.trm->curr = ft_strdup("");
	}
	if(g_tool.trm->last)
		free(g_tool.trm->last);
	g_tool.trm->last = NULL;
}

static	void printer_line(void)
{
	g_tool.trm->h_cur = tgetstr("rc",NULL);
	ft_putstr_fd(g_tool.trm->h_cur, 1);
	g_tool.trm->h_cur = tgetstr("cd",NULL);
	ft_putstr_fd(g_tool.trm->h_cur, 1);
	ft_putstr_fd(g_tool.trm->curr, 1);
}

static	void	add_a_chr(char **fin,char *s, int i)
{
	char hld[2];
	char *hold;
	
	hld[1] = 0;
	hold = *fin;
	hld[0] = s[i];
	*fin = ft_strjoin(*fin, hld);
	free(hold);
}
void	term_line(char **line, int chr)
{
	char	a_chr[2];

	a_chr[1] = 0;
	g_tool.trm->lni = (doublecount(g_tool.trm->line));
	g_tool.trm->h_cur = tgetstr("sc",NULL);
	ft_putstr_fd(g_tool.trm->h_cur, 1);
	while(1)
	{	
		chr = read_chr();
		a_chr[0] = (char)chr;
		if (chr == UP)
			up(&g_tool.trm->lni);
		else if (chr == DOWN)
			down(&g_tool.trm->lni);
		else if(chr == CTRL_D && !(g_tool.trm->curr && g_tool.trm->curr[0]))
			exit(0);
		else if(chr == DEL)
			del();
		else if(chr == NL)
			return(new_line(line));
		else if(ft_isprint(chr))
			add_a_chr(&g_tool.trm->curr, a_chr, 0); 
		printer_line();
	}
}