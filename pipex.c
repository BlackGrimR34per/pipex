/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/17 15:17:29 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmds	cmd_1;
	t_cmds	cmd_2;
	int		fd[2];
	char	**path_dir;

	if (argc != 5)
		print_error("Please enter the appropriate amount of inputs");
	pipe(fd);
	path_dir = get_path(envp);
	extract_commands(path_dir, &cmd_1, argv[2]);
	extract_commands(path_dir, &cmd_2, argv[3]);
	// int	pid_1 = fork();
	// if (pid_1 == 0)
	// {
	// 	close(fd[0]);
	// 	int	file_fd = open(argv[1], O_RDONLY);
	// 	dup2(file_fd, 0);
	// 	dup2(fd[1], 1);
	// 	execve(cmd_1.cmd_path, cmd_1.args, envp);
	// }
	// int	pid_2 = fork();
	// if (pid_2 == 0)
	// {
	// 	close(fd[1]);
	// 	int	file_fd = open(argv[4], O_CREAT | O_WRONLY, );
	// 	dup2(fd[0], 0);
	// 	dup2(file_fd, 1);
	// 	execve(cmd_2.cmd_path, cmd_2.args, envp);
	// }
	
	// close(fd[1]);
	// wait(&pid_1);
	// wait(&pid_2);
	// close(fd[0]);
	// return (0);
}
	// int	index = -1;
	// while (path_dir[++index])
	// 	free(path_dir[index]);
	// free(path_dir);
	// index = -1;
	// while (cmd_2.args[++index])
	// printf("%s", cmd_2.args[index]);
	// free(cmd_1.cmd_path);
	// free(cmd_1.args);
