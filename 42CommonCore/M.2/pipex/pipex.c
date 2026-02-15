/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 08:41:58 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/15 13:47:36 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *mess)
{
	perror(mess);
	exit(1);
}

char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**path;
	char	*full_path;

	i = 0;
	if (!cmd || !cmd[0])
		return (NULL);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		full_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(full_path, F_OK | X_OK) == 0)
			return (free_tab(path), full_path);
		free(full_path);
		i++;
	}
	return (free_tab(path), NULL);
}

void	commmand_executer(char *cmd, char **envp)
{
	char	*path;
	char	**arg;

	arg = ft_split(cmd, ' ');
	if (!arg || !arg[0])
		error_exit("argument issue");
	path = find_path(arg, envp);
	if (!path)
	{
		free_tab(arg);
		error_exit("No path");
	}
	if (execve(path, arg, envp) == -1)
	{
		free(path);
		free_tab(arg);
		error_exit("Execution issue");
	}
}

void enfants(t_pipex *folder, pid_t pid1, pid_t pid2)
{
	
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
		commmand_executer(av[2], envp);
	}
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
		commmand_executer(av[3], envp);
	}
	close(folder->pipe_fd[0]);
	close(folder->pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	close(folder->infile);
	close(folder->outfile);
	free(folder);
	return (0);
}
