/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:33 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/17 16:56:37 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_cmds
{
	char	*cmd_path;
	char	**args;
}	t_cmds;

int		check_path(char **str, t_cmds *cmd, char *cmd_str);
void	exec_child_1(t_cmds *cmds, int *fds, char *file, char *envp[]);
void	exec_child_2(t_cmds *cmds, int *fds, char *file, char *envp[]);
void	extract_commands(char **path, t_cmds *cmd, char *cmd_str);
void	free_cmd(t_cmds *cmds);
void	free_path(char **path);
char	**get_path(char *envp[]);
void	print_error(char *msg);

#endif