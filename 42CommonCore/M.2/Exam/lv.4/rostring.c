/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:32:54 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/31 10:41:47 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void	rostring(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] && str[i] == ' ' || str[i] == '\t') // on saute les \t et les tab
		i++;
	j = i; // j pointe sur le DÉBUT du premier mot
	while (str[i])
	{
        // Sauter le premier mot
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
        // Sauter les espaces
		while (str[i] && (str[i] == ' ' || str[i] == '\t')) 
			i++;

        // Tant que j'ai une lettre et que just avant j'avais un espace ou un tab
		while ((str[i] && (str[i] != ' ' && str[i] != '\t')) && (str[i- 1] == ' ' || str[i - 1] == '\t'))
		{
            // Afficher les mots suivants
			while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			{
				write(1, &str[i], 1);
				i++;
			}
			write(1, " ", 1);
			i++;
		}
	}
    // Afficher le premier mot (sauvegardé par
	while (str[j] && (str[j] != ' ' && str[j] != '\t'))
	{
		write(1, &str[j], 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		rostring(av[1]);
	}
	write(1, "\n", 1);
	return (0);
}