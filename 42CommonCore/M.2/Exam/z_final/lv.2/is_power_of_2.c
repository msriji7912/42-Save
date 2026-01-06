/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:17:37 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 10:24:28 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int is_power_of_2(unsigned int n)
{
    unsigned int i;

    i = 1;
    if (n == 0)
        return (0);
    while (1)
    {
        if (i > n) //small logical mistake !!
            return (0);
        else if (n == i)
            return (1);
        i *= 2;
    }
}

int main (void)
{
    unsigned int n = 6;
    printf("%d", is_power_of_2(n));
    return (0);
}