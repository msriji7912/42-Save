/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex .c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 09:32:50 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/14 17:17:09 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	int	in_fd;
	int	out_fd;

	if (ac != 5) // Argument check
	{
		arg_err();
		return (1);
	}
	in_fd = open(av[1], O_RDONLY); // infile check and opend
	if (in_fd == -1)
	{
		perror("Couldn't read it");
		exit(1);
	}
	out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644); // outfile check and open
	if (out_fd == -1)
	{
		perror("Outfile error");
		exit(1);
	}
	if (parsing(ac, av))
		return (1);
	// other functions
	// free_tab(cmd1);
	// free_tab(cmd2);
	close(in_fd);
	close(out_fd);
}
