/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/27 21:35:28 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_here_doc(char *limiter)
{
	int		fds[2];
	char	*line;
	size_t	limiter_length;

	if (pipe(fds) == -1)
		printf("5 BIG BOOMS");
	limiter_length = ft_strlen(limiter);
	while (true)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			exit(0);
		if (ft_strncmp(line, limiter, limiter_length) == 0
			&& line[limiter_length] == '\n')
		{
			free(line);
			break ;
		}
		write(fds[1], line, ft_strlen(line));
		free(line);
	}
	close(fds[1]);
	return (fds[0]);
}

void	handle_execution(char *argv[], int start, int input, int output)
{
	int	argc;
	int	index;

	(void)start;
	(void)input;
	(void)output;

	argc = 0;
	while (argv[argc])
		argc++;
	index = start;
	while (++index < argc - 1)
		
}

int	main(int argc, char *argv[], char *envp[])
{
	(void)envp;
	int	input_fd;
	int	output_fd;

	if (argc < 5)
		print_error("Please enter the appropriate amount of inputs");
	if (ft_strcmp(argv[1], HERE_DOC) == 0)
	{
		input_fd = handle_here_doc(argv[2]);	printf("%d\n", argc);
		output_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND);
		handle_execution(argv, 0, 0, 0);
	}
	else
	{
		input_fd = open(argv[1], O_RDONLY);
		output_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC);
		handle_execution(argv, 0, 0, 0);
	}
	// if (pipe(fd) == -1)
	// 	return (1);
	// pid_1 = exec_child_1(envp, argv, fd);
	// pid_2 = exec_child_2(envp, argv, fd);
	// close(fd[0]);
	// close(fd[1]);
	// waitpid(pid_1, NULL, 0);
	// waitpid(pid_2, &w_status, 0);
	// if (WIFEXITED(w_status))
	// {
	// 	status_code = WEXITSTATUS(w_status);
	// 	if (status_code != 0)
	// 		exit(status_code);
	// }
	// return (0);
}
