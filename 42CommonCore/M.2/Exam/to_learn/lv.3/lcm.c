/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:04:55 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 10:00:17 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//LCM is the smallest positive number that can be evenly divided by both input numbers.
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int n;
	unsigned int res_gcd;
	unsigned int save_a;
	unsigned int save_b;

	// 1. Si l'un des deux est 0, le LCM est 0
	if (a == 0 || b == 0)
		return (0);

	save_a = a;
	save_b = b;

    // The greatest common divisor (GCD)
	// 2. On calcule d'abord le GCD (ton algorithme d'Euclide)
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	res_gcd = a;

	// 3. On applique la formule : (a * b) / GCD
	return ((save_a * save_b) / res_gcd);
}
