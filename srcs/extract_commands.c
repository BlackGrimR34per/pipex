/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:45:02 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/17 15:22:06 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	extract_commands(char **path, t_cmds *cmd, char *cmd_str)
{
	cmd->args = ft_split(cmd_str, ' ');
	if (check_path(path, cmd, cmd->args[0]))
		print_error("Please retry with an appropriate command\n");
}
