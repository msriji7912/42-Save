/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:39:02 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/14 12:44:34 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile

int	parsing(int ac, char *av[])
{
	int		in_fd;
	int		out_fd;
	char	**cmd1;
	char	**cmd2;

    if (ac != 5) // Argument check
    {
        arg_err();
        return (1);
    }
	in_fd = open(av[1], O_RDONLY); // infile check
	if (in_fd == -1)
		perror("Couldn't read it");
	out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // outfile check
	if (out_fd == -1)
	{
    	perror("Outfile error");
        exit(1);
    }
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	// + function to Find executable paths
    free_tab(cmd1);
    free_tab(cmd2);
    return (0);
}
