/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abferrer <abferrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 19:36:48 by abferrer          #+#    #+#             */
/*   Updated: 2025/11/03 16:41:01 by abferrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_child(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY);
	if (input_file == -1)
	{
		ft_error("Error reading input file...");
		exit(1);
	}
	if (dup2(input_file, STDIN_FILENO) == -1)
	{
		ft_error("dup2 failed");
		exit(1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		ft_error("dup2 failed");
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	close(input_file);
	execute(argv[2], envp);
	ft_error("exec failed");
	exit(1);
}

static void	second_child(char **argv, char **envp, int *fd)
{
	int	output_file;

	output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_file == -1)
	{
		ft_error("Error writing output file...");
		exit(1);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		ft_error("dup2 failed");
		exit(1);
	}
	if (dup2(output_file, STDOUT_FILENO) == -1)
	{
		ft_error("dup2 failed");
		exit(1);
	}
	close(fd[0]);
	close(fd[1]);
	close(output_file);
	execute(argv[3], envp);
	ft_error("exec failed");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (ft_putstr_fd("Invalid arguments number\n", 2), 1);
	if (access(argv[1], F_OK) == -1)
		return (ft_error("Input file does not exist"), 1);
	if (pipe(pipe_fd) == -1)
		ft_error("Error creating pipe");
	pid1 = fork();
	if (pid1 == -1)
		return (ft_error("Error creating first fork..."), 1);
	if (pid1 == 0)
		first_child(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		return (ft_error("Error creating second fork..."), 1);
	if (pid2 == 0)
		second_child(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
