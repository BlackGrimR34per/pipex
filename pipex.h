/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:33 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/27 00:23:05 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

# define HERE_DOC "here_doc"

typedef struct s_cmds
{
	char	*cmd_path;
	char	**args;
}	t_cmds;

int		check_path(t_cmds *cmd, char **path, char *cmd_str);
pid_t	exec_child_1(char *envp[], char *argv[], int *fds);
pid_t	exec_child_2(char *envp[], char *argv[], int *fds);
void	extract_commands(t_cmds *cmd, char **path, char *arg_str);
void	free_cmd_args(t_cmds *cmd);
void	free_cmd(t_cmds *cmd);
void	free_path(char **path);
char	**get_path(char *envp[]);
void	print_error(char *msg);

#endif