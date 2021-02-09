/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjmari <tjmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:31:49 by tjmari            #+#    #+#             */
/*   Updated: 2021/02/09 17:03:06 by tjmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL
# define MINISHELL

# include <stdlib.h> // malloc(3), free(3), exit(3)
# include <unistd.h> // write(2), read(2), close(2), fork(2), getcwd(3), chdir(2), execve(2), dup(2), dup2(2), pipe(2)
# include <fcntl.h> // open(2)
# include <sys/wait.h> // wait(2), wait3(2), wait4(2), waitpid(2)
# include <signal.h> // signal(3), kill(2)
# include <sys/stat.h> // stat(2), lstat(2), fstat(2)
# include <dirent.h> // opendir(3), readdir(3), closedir(3)
# include <stdio.h> // strerror(3)
# include <sys/errno.h> // errno(2)

#endif
