/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:09:32 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/30 14:45:44 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	    is_power_of_2(unsigned int n)
{
    unsigned int nbr;

    nbr = 1;
    if (n == 0)
        return (0);
    while (1)
    {
        if (nbr == n)
            return (1);
        else if (nbr > n)
            return (0);
        nbr *= 2;
    }
}

int	is_power_of_2(unsigned int n)
{
	if (n == 0) // on verifie si n est egal a 0
		return (0);
	while (n % 2 == 0) // tant qu'il est divisible par 2 on le divise par 2
		n /= 2;
	if (n == 1) // si a la fin de la boucle n n'est pas a 1 ce n'est pas une puissance de 2
		return (1);
	else
		return (0);
}

int main(void)
{
    unsigned int n = 72;
    if (is_power_of_2(n) == 1)
        printf("%d Is a power of 2!", n);
    if (is_power_of_2(n) == 0)
        printf("%d Is not a power of 2!", n);
    return (0);
}