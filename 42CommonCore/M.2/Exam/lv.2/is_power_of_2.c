/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:09:32 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:26:55 by mosriji          ###   ########.fr       */
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

int main (void)
{
    unsigned int n = 6;
    printf("%d", is_power_of_2(n));
    return (0);
}