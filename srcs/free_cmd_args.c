/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:47:39 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/21 13:53:15 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_cmd_args(t_cmds *cmd)
{
	int	index;

	index = -1;
	while (cmd->args[++index])
		free(cmd->args[index]);
	free(cmd->args);
}
