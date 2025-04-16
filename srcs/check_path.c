/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:23:54 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/16 21:04:31 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_path(char **path, t_cmds *cmd, char *cmd_str)
{
	int		index;
	char	*cmd_path;

	index = -1;
	while (path[++index])
	{
		cmd_path = ft_strjoinv(3, path[index], "/", cmd_str);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			cmd->cmd_path = cmd_path;
			return (0);
		}
		free(cmd_path);
	}
	return (1);
}
