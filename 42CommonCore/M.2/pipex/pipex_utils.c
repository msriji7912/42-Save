/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:37:04 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/21 01:26:07 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	full_error_cmd2(char *mess, t_pipex *folder)
{
	perror(mess);
	safe_closing(folder->infile);
	safe_closing(folder->outfile);
	free(folder);
	exit(127);
}

char	*find_path(char **cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**path;
	char	*full_path;

	i = 0;
	if (cmd[0] && cmd[0][0] == '/' && (access(cmd[0], F_OK | X_OK) == 0))
		return (ft_strdup(cmd[0]));
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!cmd || !cmd[0] || !envp[i])
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

void	exec_enfant_1(char *cmd, char **envp, t_pipex *folder)
{
	char	*path;
	char	**arg;

	arg = ft_split(cmd, ' ');
	if (!arg || !arg[0])
		full_error("argument issue", folder);
	path = find_path(arg, envp);
	if (!path)
	{
		free_tab(arg);
		full_error("No path", folder);
	}
	if (execve(path, arg, envp) == -1)
	{
		free(path);
		free_tab(arg);
		write(2, "Execution issue", 16);
		exit(0);
	}
}

void	exec_enfant_2(char *cmd, char **envp, t_pipex *folder)
{
	char	*path;
	char	**arg;

	arg = ft_split(cmd, ' ');
	if (!arg || !arg[0])
		full_error_cmd2("argument issue", folder);
	path = find_path(arg, envp);
	if (!path)
	{
		free_tab(arg);
		full_error_cmd2("No path", folder);
	}
	if (execve(path, arg, envp) == -1)
	{
		free(path);
		free_tab(arg);
		full_error_cmd2("Execution issue", folder);
	}
}
