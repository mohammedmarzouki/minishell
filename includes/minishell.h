/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarzouk <mmarzouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:31:49 by tjmari            #+#    #+#             */
/*   Updated: 2021/04/08 12:15:36 by mmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h> // malloc(3), free(3), exit(3)
# include <unistd.h> // write(2), read(2), close(2), fork(2), getcwd(3), chdir(2), execve(2), dup(2), dup2(2), pipe(2)
# include <fcntl.h> // open(2)
# include <sys/wait.h> // wait(2), wait3(2), wait4(2), waitpid(2)
# include <signal.h> // signal(3), kill(2)
# include <sys/stat.h> // stat(2), lstat(2), fstat(2)
# include <dirent.h> // opendir(3), readdir(3), closedir(3)
# include <stdio.h>
# include <string.h> // strerror(3)
# include <sys/errno.h> // errno(2)
# include "../libft/libft.h"

#define HI printf("HI\n");

typedef	struct	s_tool
{
	int			cmd_c;
	int			cmd_i;
	char		cwd[1024];
	char		**envp;
}				t_tool;

typedef	struct	s_cmd
{
	char		**args;
	char		*sep;
	char		**red;
	char		**file;
}				t_cmd;

t_cmd			*g_cmd;
t_tool			g_tool;

/*
** GENERAL
*/
void			ps1(void);

/*
** PARSING
*/
int				parsing(char *s);
int				get_next_line(int fd, char **line);
void			init_s_cmd(t_cmd *cmd);
void			ft_crop(char *src ,char **des ,int start ,int end);
void			nfree(void *s);
int				same(char *s1, char *s2);
void			doublefree(char **ptr);
int				doublecount(char **s);
int				itis(char *s);
char			**append_line(char **s, char *line);
int				a_word(char *s);
void			ft_crop(char *src ,char **des ,int start ,int end);
char			**split_it(char *s);
void			assign(char **sp);

/*
** EXECUTING
*/
void			executing(void);
void			ft_echo(void);
void			ft_cd(void);
void			ft_pwd(void);
void			ft_export(void);
void			ft_unset(void);
void			ft_env(void);
void			ft_exit(void);

#endif
