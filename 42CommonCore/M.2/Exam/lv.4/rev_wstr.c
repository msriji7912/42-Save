/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:42:17 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 10:04:50 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int save;

	i = 0;
	if (ac == 2)
	{
		while (av[1][i])
			i++;
		i--;
		while (i >= 0) // ou alors av[1][i]
		{
            while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
                i--;
            while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
                i--;
            save = i;
            i++;
            while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            {
                write(1, &av[1][i], 1);
                i++;
            }
            i = save;
            if (i > 0)
                write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
    return (0);
}