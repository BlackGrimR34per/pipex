/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/17 16:57:31 by yosherau         ###   ########.fr       */
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
	exec_child_1(&cmd_1, fd, argv[1], envp);
	exec_child_2(&cmd_2, fd, argv[4], envp);
	free_path(path_dir);
	free_cmd(&cmd_1);
	free_cmd(&cmd_2);
}
