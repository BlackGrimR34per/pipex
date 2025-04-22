/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:46:13 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/22 11:50:34 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

//Check for file opening error and path dir
pid_t	exec_child_1(char *envp[], char *argv[], int *fds)
{
	pid_t	pid;
	int		fd;
	t_cmds	cmd;
	char	**path_dir;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		close(fds[0]);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			exit(1);
		path_dir = get_path(envp);
		extract_commands(&cmd, path_dir, argv[2]);
		dup2(fd, 0);
		dup2(fds[1], 1);
		execve(cmd.cmd_path, cmd.args, envp);
		free_cmd(&cmd);
		free_path(path_dir);
		exit(1);
	}
	return (pid);
}
