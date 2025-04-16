/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/16 21:37:48 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmds	cmd_1;
	t_cmds	cmd_2;
	int		fd[2];
	char	**path_dir;

	pipe(fd);
	if (argc != 5)
		print_error("Please enter the appropriate amount of inputs");
	path_dir = get_path(envp);
			extract_commands(path_dir, &cmd_1, argv[2]);
	extract_commands(path_dir, &cmd_2, argv[3]);
	printf("%d\n", fd[0]);
	


	int	index = -1;
	// while (path_dir[++index])
	// 	free(path_dir[index]);
	// free(path_dir);
	index = -1;
	while (cmd_2.args[++index])
		printf("%s", cmd_2.args[index]);
	// free(cmd_1.cmd_path);
	// free(cmd_1.args);
}
