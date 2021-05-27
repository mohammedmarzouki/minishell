/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:04:07 by tjmari            #+#    #+#             */
/*   Updated: 2021/05/27 12:25:21 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include "../libft/libft.h"

typedef struct s_cmd
{
	char		**args;
	char		*sep;
	char		**red;
	char		**file;
}				t_cmd;

typedef struct s_tool
{
	int			cmd_c;
	int			cmd_i;
	char		cwd[1024];
	short		exterr;
	t_cmd		**cmd;
	char		**envp;
	int			original_fd_in;
	int			original_fd_out;
	int			fd_in;
	int			fd_out;
	int			which_builtin;
}				t_tool;
t_tool			g_tool;

/*
** PARSING
*/
int				parsing(char *s);
int				get_next_line(char **line);
void			nfree(void *s);
int				same(char *s1, char *s2);
char			**doublefree(char **ptr);
int				doublecount(char **s);
int				itis(char *s);
char			**append_line(char **s, char *line, int free);
int				a_word(char *s);
char			**split_it(char *s, char **sp, int i, int start);
void			assign(char **sp);
short			chk_err(char **sp);
int				seterr(short err);
int				count_cmds(char **s);

/*
** EXECUTING
*/
void			executing(void);
void			run_builtin(int i);
void			run_infork(int i);
char			*make_cmd(char **paths, char *cmd);

_Bool			set_redirections(t_cmd *cmd);
void			reset_std(void);

_Bool			based_pipe_fork(int i);
void			single_cmd_infork(int i);

void			is_builtin(int i);
void			ft_echo(int i);
_Bool			ft_isflag(char *args);
void			ft_cd(int i);
void			ft_pwd(void);
void			ft_export(int i);
void			ft_putexport(char **argv);
void			ft_unset(int i);
int				ft_is_empty(char *s);
int    			ft_envremove(char *var);
void			ft_env(void);
void			ft_exit(int i);
_Bool			ft_isnumeric(char *arg);

int				how_many_element(char **argv);
char			**ft_dcdup(char **argv, int toadd);
char			**sortdcp(char **argv);
char			**add_node_dc(char **argv, char **cmds, int nodes);
void			change_var(char *var, char *new_value);
void			change_shlvl(void);

#endif
