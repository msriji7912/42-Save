/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 10:23:18 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/31 10:31:49 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int tmp; // tmp pour le swap
	unsigned int i;
	unsigned int j;

	i = 0;
	while (i < size - 1) //  Pas besoin de traiter le dernier élément car on le compare avec rien
	{
		j = i; // pour chaque position de i, j va comparer avec toutes les valeurs du tab
		while (j < size) // tant 
        {
			if (tab[i] > tab[j])  // on swap les valeurs 
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}