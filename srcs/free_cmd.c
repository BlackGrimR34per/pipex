/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:48:56 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/17 16:52:53 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_cmd(t_cmds *cmd)
{
	int	index;

	index = -1;
	while (cmd->args[++index])
		free(cmd->args[index]);
	free(cmd->args);
	free(cmd->cmd_path);
}
