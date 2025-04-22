/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 23:25:29 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/21 14:34:46 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_path(t_cmds *cmd, char **path, char *cmd_str)
{
	int		index;
	char	*full_cmd_path;

	index = -1;
	while (path[++index])
	{
		full_cmd_path = ft_strjoinv(3, path[index], "/", cmd_str);
		if (access(full_cmd_path, F_OK | X_OK) == 0)
		{
			cmd->cmd_path = full_cmd_path;
			return (0);
		}
		free(full_cmd_path);
	}
	return (1);
}
