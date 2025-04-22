/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/22 12:03:09 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	pid_t	pid_1;
	pid_t	pid_2;
	int		fd[2];
	int		w_status;
	int		status_code;

	if (argc != 5)
		print_error("Please enter the appropriate amount of inputs");
	if (pipe(fd) == -1)
		return (1);
	pid_1 = exec_child_1(envp, argv, fd);
	pid_2 = exec_child_2(envp, argv, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, &w_status, 0);
	if (WIFEXITED(w_status))
	{
		status_code = WEXITSTATUS(w_status);
		if (status_code != 0)
			exit(status_code);
	}
	return (0);
}
