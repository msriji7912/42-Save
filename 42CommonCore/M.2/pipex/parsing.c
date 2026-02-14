/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:39:02 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/14 18:18:40 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile

char **parsing(int ac, char *av[])
{
	char	**cmd1;
	char	**cmd2;

	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	if (!cmd1 || !cmd2)
		return (1);
	// + function to Find executable paths
	return (cmd1, cmd2);
}

char	*finding_path(char **cmd, char **envp)
{
	int		i;
	char	*tmp;
	char	**path;
	char	*full_path;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
    	return (NULL);
	path = split(envp[i] + 5, ':'); // gather the path
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
