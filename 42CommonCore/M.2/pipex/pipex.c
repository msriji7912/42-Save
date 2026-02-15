/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:41:58 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/15 15:56:42 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

pid_t	enfant_1(t_pipex *folder, char *av[], char **envp)
{
	pid_t	pid1;

	pid1 = fork();
	if (pid1 < 0)
		error_exit("fork child1 issue");
	if (pid1 == 0)
	{
		close(folder->pipe_fd[0]);
		dup2(folder->infile, STDIN_FILENO);
		dup2(folder->pipe_fd[1], STDOUT_FILENO);
		close(folder->infile);
		close(folder->pipe_fd[1]);
		exec_enfant_1(av[2], envp);
	}
	return (pid1);
}

pid_t	enfant_2(t_pipex *folder, char *av[], char **envp)
{
	pid_t	pid2;

	pid2 = fork();
	if (pid2 < 0)
		error_exit("fork child1 issue");
	if (pid2 == 0)
	{
		close(folder->pipe_fd[1]);
		dup2(folder->pipe_fd[0], STDIN_FILENO);
		dup2(folder->outfile, STDOUT_FILENO);
		close(folder->outfile);
		close(folder->pipe_fd[0]);
		exec_enfant_1(av[3], envp);
	}
	return (pid2);
}

void	parent(t_pipex *folder, pid_t pid1, pid_t pid2)
{
	close(folder->pipe_fd[0]);
	close(folder->pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(folder->infile);
	close(folder->outfile);
}

int	main(int ac, char *av[], char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	t_pipex	*folder;

	folder = malloc(sizeof(t_pipex));
	if (!folder)
		error_exit("Folder issue");
	if (ac != 5)
	{
		write(2, "Not the right number of arguments", 34);
		exit(1);
	}
	folder->infile = open(av[1], O_RDONLY);
	if (folder->infile < 0)
		error_exit("Couldn't open infile");
	folder->outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (folder->outfile < 0)
		error_exit("Couldn't open/create outfile");
	if (pipe(folder->pipe_fd) == -1)
		error_exit("Pipe error");
	pid1 = enfant_1(folder, av, envp);
	pid2 = enfant_2(folder, av, envp);
	parent(folder, pid1, pid2);
	free(folder);
	return (0);
}
