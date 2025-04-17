/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:33 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/17 14:37:08 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_cmds
{
	char	*cmd_path;
	char	**args;
}	t_cmds;

int		check_path(char **str, t_cmds *cmd, char *cmd_str);
void	extract_commands(char **path, t_cmds *cmd, char *cmd_str);
char	**get_path(char *envp[]);
void	print_error(char *msg);

#endif