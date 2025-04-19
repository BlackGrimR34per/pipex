/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:34:29 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/20 00:24:15 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_child_2(t_cmds *cmds, int *fds, char *file, char *envp[])
{
	int	fd;
	int	pid;
	int	parent_status;
	int	status;

	pid = fork();
	if (pid < 0)
		return ;
	if (pid == 0)
	{
		close(fds[1]);
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd < 0)
			return ;
		dup2(fds[0], 0);
		dup2(fd, 1);
		execve(cmds->cmd_path, cmds->args, envp);
	}
	close(fds[0]);
	wait(&parent_status);
	if (WIFEXITED(parent_status))
	{
		status = WEXITSTATUS(parent_status);
		if (status != 0)
			exit(status);
	}
}
