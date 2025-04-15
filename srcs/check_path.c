/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:23:54 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/15 21:09:15 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_path(char **str, t_cmds *cmd, char *cmd_str)
{
	int		index;
	char	*path;

	index = -1;
	while (str[++index])
	{
		path = ft_strjoin(str[index], cmd_str);
		if (access(path, F_OK | X_OK) == 0)
		{
			cmd->cmd_path = path;
			return (0);
		}
	}
	return (1);
}
