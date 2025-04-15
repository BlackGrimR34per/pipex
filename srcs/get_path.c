/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:06:30 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/15 19:46:35 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path(char *envp[])
{
	char	*path;
	int		index;

	index = -1;
	while (envp[++index])
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
			path = envp[index] + 5;
	if (!path)
		return (NULL);
	return (ft_split(path, ':'));
}