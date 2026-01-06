/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:42:17 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/31 11:02:28 by mosriji          ###   ########.fr       */
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
		while (av[1][i]) // on va a la fin de la str
			i++;
		i--; // passer le \0, i pointe sur le dernier caractère
		while (i >= 0) // tant que i n'est pas a 0
		{
            // Sauter les espaces/tabs avant le mot
			while (i > 0 && (av[1][i] == ' ' || av[1][i] == '\t')) // on saute les \t et espaces present avant un mot ou entre
				i--;
            // Reculer jusqu'au début du mot
			while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t') // on recupere le mot 
				i--;
            // Sauvegarder la position et avancer d'un cran
			save = i;
			i++; // i pointe maintenant sur la 1ère lettre du mot
            // Afficher le mot
			while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0') // on write le mot
			{
            	write(1, &av[1][i], 1);
                i++;
            }
            i = save; // on mets i a save donc on retourne au debut du mot
			if (av[1][i] > 0) // on mets un espaces si c'est pas le dernier mots
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
    return (0);
}