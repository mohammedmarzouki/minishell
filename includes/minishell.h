/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 20:04:07 by tjmari            #+#    #+#             */
/*   Updated: 2021/06/02 11:08:10 by tjmari           ###   ########.fr       */
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
	int			pipe[2];
}				t_cmd;

typedef struct s_tool
{
	int			cmd_c;
	int			i;
	char		cwd[1024];
	int			exit_status;
	t_cmd		**cmd;
	char		**envp;
	int			original_fd_in;
	int			original_fd_out;
	int			fd_in;
	int			fd_out;
	int			which_builtin;
	pid_t		pid;
	_Bool		exit_flag;
}				t_tool;
t_tool			g_tool;

/*
** PARSING
*/
int				parsing(char *s);
int				get_next_line(char **line);
int				same(char *s1, char *s2);
int				doublecount(char **s);
int				itis(char *s);
int				pipe_tkn(int *f,int *i,char **sp);
int				semicln_tkn(int *f,int *i);
int				a_word(char *s);
int				seterr(short err);
int				err_quit(char *s,int err);
int				count_cmds(char **s);
int				get_env(char *s);
int				redirct_tkn(int *f,int *i,char **sp);
int 			backslash(char *s);
char			**doublefree(char **ptr);
char			**append_line(char **s, char *line, int free);
char			**split_it(char *s, char **sp, int i, int start);
void			cmd_arg(int *f,int *i);
void			finalizem(int	i);
void			assign(char **sp);
void			nfree(void *s);
void			fin_slash(char **fin,char *s, int *i);
void			fin_quote(char **fin,char *s, int *i);
void			fin_sngl_q(char **fin,char *s, int *i);
void			fin_vars(char **fin,char *s, int *i);
void			fin_nrml(char **fin,char *s, int *i);
void			fin_err(char **fin, int *i);
short			chk_err(char **sp,int i,int value,int flag);

/*
** EXECUTING
*/
void			executing(void);
void			run_builtin(int i);
void			run_infork(int i);
char			*make_cmd(char **paths, char *cmd);

void			signal_int(int sig);
void			signal_quit(int sig);

_Bool			set_redirections(t_cmd *cmd);
void			reset_std(void);

void			cmd_infork(int i);
_Bool			based_pipe_fork(int i);
void			open_pipe(int i);
void			set_pipe(int i);

void			is_builtin(int i);
void			ft_echo(int i);
_Bool			ft_isflag(char *args);
void			ft_cd(int i);
void			ft_pwd(void);
void			ft_export(int i);
int				how_many_nodes(int i);
char			**change_envp_var(char **argv, int index, char *arg);
char			*ft_getkey(char *arg);
char			*ft_getvalue(char *arg);
_Bool			ft_export_valid(char *cmd);
void			ft_putexport(char **argv);
void			ft_unset(int i);
int				ft_isempty(char *s);
int				ft_envremove(char *var);
void			ft_env(void);
void			ft_exit(int i);
_Bool			ft_isnumeric(char *arg);
void			ft_printexit(int i);

int				how_many_element(char **argv);
char			**ft_dcdup(char **argv, int toadd);
char			**sortdcp(char **argv);
char			**add_node_dc(char **argv, char **cmds, int nodes);
void			change_shlvl(void);
void			unset_oldpwd(void);

#endif
