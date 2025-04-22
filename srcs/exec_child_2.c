/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:15:31 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/22 12:02:22 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

pid_t	exec_child_2(char *envp[], char *argv[], int *fds)
{
	int		fd;
	int		pid;
	t_cmds	cmd;
	char	**path_dir;

	pid = fork();
	if (pid < 0)
		exit (1);
	if (pid == 0)
	{
		close(fds[1]);
		fd = open(argv[4], O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (fd < 0)
			exit (1);
		path_dir = get_path(envp);
		extract_commands(&cmd, path_dir, argv[3]);
		dup2(fds[0], 0);
		dup2(fd, 1);
		execve(cmd.cmd_path, cmd.args, envp);
		free_cmd(&cmd);
		free_path(path_dir);
	}
	return (pid);
}
