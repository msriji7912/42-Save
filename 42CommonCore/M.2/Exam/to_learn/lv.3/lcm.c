/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:04:55 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 15:32:42 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int n;
	unsigned int res_gcd;
	unsigned int save_a;
	unsigned int save_b;


	if (a == 0 || b == 0)
		return (0);

	save_a = a;
	save_b = b;

	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	res_gcd = a;

	return ((save_a * save_b) / res_gcd);
}
