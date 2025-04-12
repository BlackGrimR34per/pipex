/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/04/12 14:05:27 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{

	int		fd[2];
	int		child_id;
	char	*str[] = {
		"/bin/ls",
		NULL
	};

	if (argc != 5)
		print_error("Please enter the appropriate amount of inputs");
	execve("/bin/ls", str, 0);
	return (0);
}
