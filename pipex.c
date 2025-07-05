/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:02:24 by yosherau          #+#    #+#             */
/*   Updated: 2025/07/05 19:06:37 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Change the error handling when pipe fails to create a pipe
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

void	handle_execution(char *envp[], char *argv[], int start, int input, int output)
{
	int		argc;
	int		index;
	int		fds[2];
	pid_t	pid;
	char	**path_dir;
	t_cmds	cmd;

	argc = 0;
	while (argv[argc])
		argc++;
	index = start;
	while (index < argc - 1)
	{
		pipe(fds);
		pid = fork();
		if (pid == 0)
		{
			path_dir = get_path(envp);
			extract_commands(&cmd, path_dir, argv[index]);
			dup2(input, STDIN_FILENO);
			if (index != argc - 2)
				dup2(fds[1], STDOUT_FILENO);
			else
				dup2(output, STDOUT_FILENO);
			execve(cmd.cmd_path, cmd.args, envp);
			close(fds[0]);
			close(fds[1]);
		}
		else
		{
			close(fds[1]);
			if (input != STDIN_FILENO)
				close(input);
			input = fds[0];
		}
		index++;
	}
	while (wait(NULL) > 0);
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
		input_fd = handle_here_doc(argv[2]);
		output_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND);
		handle_execution(envp, argv, 3, input_fd, output_fd);
	}
	else
	{
		input_fd = open(argv[1], O_RDONLY);
		output_fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC);
		handle_execution(envp, argv, 2, input_fd, output_fd);
	}
}
