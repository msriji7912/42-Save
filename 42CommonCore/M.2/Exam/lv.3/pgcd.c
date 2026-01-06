/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:07:54 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 10:03:24 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int	n = a;

	while (n > 0) // tant que n n'est pas = 0 on verifie si il est un denominateur commun de a et b
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n); // si il l'est on le print et on return
			return ;
		}
		--n;
	}
}

int	main(int ac, char **av)
{
	if (ac == 3)
		pgcd(atoi(av[1]), atoi(av[2]));
	printf("\n");
}