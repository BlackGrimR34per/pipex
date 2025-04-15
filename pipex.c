/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/15 20:53:05 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_cmds	cmd_1;
	t_cmds	cmd_2;
	char	**path_dir;

	if (argc != 5)
		print_error("Please enter the appropriate amount of inputs");
	path_dir = get_path(envp);
	extract_commands(path_dir, &cmd_1, argv[1]);
	
	
	int	index = -1;
	while (cmd_1.args[++index])
		free(cmd_1.args[index]);
	free(cmd_1.args);
	free(cmd_1.cmd_path);
	// path_dir = get_path(envp);
}
