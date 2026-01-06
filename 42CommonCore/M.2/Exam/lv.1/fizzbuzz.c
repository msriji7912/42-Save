/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 07:54:40 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 08:04:03 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void mini_putchar(char c)
{
    write(1, &c, 1);
}

void mini_putnbr(int nbr)
{
    if (nbr > 9)
        mini_putnbr(nbr / 10);
    mini_putchar((nbr % 10) + '0');
}

int main(void)
{
    int nbr;

    nbr = 1;
    while (nbr < 100)
    {
        if ((nbr % 3 == 0) && (nbr % 5 == 0))
            write(1, "fizzbuzz", 8);
        else if (nbr % 3 == 0)
            write(1, "fizz", 4);
        else if (nbr % 5 == 0)
            write(1, "buzz", 4);
        else
            mini_putnbr(nbr);
        write(1, "\n", 1);
        nbr++;
    }
    return(0);
}
