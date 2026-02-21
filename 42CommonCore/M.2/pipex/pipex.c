/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:41:58 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/21 01:21:43 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	enfant_1(t_pipex *folder, char *av[], char **envp)
{
	pid_t	pid1;

	if (folder->infile == -1)
		exit(1);
	pid1 = fork();
	if (pid1 < 0)
		full_error("fork child1 issue", folder);
	if (pid1 == 0)
	{
		close(folder->pipe_fd[0]);
		if (dup2(folder->infile, STDIN_FILENO) == -1)
			full_error("dup2 failed", folder);
		if (dup2(folder->pipe_fd[1], STDOUT_FILENO) == -1)
			full_error("dup2 failed", folder);
		safe_closing(folder->infile);
		close(folder->pipe_fd[1]);
		exec_enfant_1(av[2], envp, folder);
	}
	return (pid1);
}

pid_t	enfant_2(t_pipex *folder, char *av[], char **envp)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
		full_error("fork child1 issue", folder);
	if (pid2 == 0)
	{
		close(folder->pipe_fd[1]);
		if (dup2(folder->pipe_fd[0], STDIN_FILENO) == -1)
			full_error("dup2 failed", folder);
		if (dup2(folder->outfile, STDOUT_FILENO) == -1)
			full_error("dup2 failed", folder);
		safe_closing(folder->outfile);
		close(folder->pipe_fd[0]);
		exec_enfant_2(av[3], envp, folder);
	}
	return (pid2);
}

int	parent(t_pipex *folder, pid_t pid1, pid_t pid2)
{
	int	status;
	int	exit_code;

	close(folder->pipe_fd[0]);
	close(folder->pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	safe_closing(folder->infile);
	safe_closing(folder->outfile);
	if (WIFEXITED(status))
		exit_code = WEXITSTATUS(status);
	else
		exit_code = 1;
	return (exit_code);
}

int	main(int ac, char *av[], char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		final_exit;
	t_pipex	*folder;

	folder = malloc(sizeof(t_pipex));
	if (!folder)
		error_regular_exit("Folder issue");
	if (ac != 5)
		arg_issue(folder);
	folder->infile = open(av[1], O_RDONLY);
	if (folder->infile < 0)
		perror("Couldn't open the infile");
	folder->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (folder->outfile < 0)
		error_exit_fd("Couldn't open/create outfile", folder);
	if (pipe(folder->pipe_fd) == -1)
		full_error("Pipe error", folder);
	pid1 = enfant_1(folder, av, envp);
	pid2 = enfant_2(folder, av, envp);
	final_exit = parent(folder, pid1, pid2);
	free(folder);
	return (final_exit);
}
