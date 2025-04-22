/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 23:24:22 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/21 14:46:09 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	extract_commands(t_cmds *cmd, char **path, char *cmd_str)
{
	if (!(*cmd_str))
	{
		free_path(path);
		exit(0);
	}
	cmd->args = ft_split(cmd_str, ' ');
	if (access(cmd->args[0], F_OK | X_OK) == 0)
	{
		cmd->cmd_path = ft_strdup(cmd->args[0]);
		return ;
	}
	if (check_path(cmd, path, cmd->args[0]))
	{
		free_cmd_args(cmd);
		free_path(path);
		exit(127);
	}
}
