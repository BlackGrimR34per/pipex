/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:46:13 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/20 17:12:54 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_child_1(t_cmds *cmds, int *fds, char *file, char *envp[])
{	
	int	fd;
	int	pid;

	// pid = fork();
	// if (pid < 0)
	// 	return ;
	// if (pid == 0)
	// {
	// 	close(fds[0]);
	// 	fd = open(file, O_RDONLY);
	// 	if (fd < 0)
	// 		exit(1);
	// 	dup2(fd, 0);
	// 	dup2(fds[1], 1);
	// 	execve(cmds->cmd_path, cmds->args, envp);
	// }
	// close(fds[1]);
	// wait(NULL);
}
