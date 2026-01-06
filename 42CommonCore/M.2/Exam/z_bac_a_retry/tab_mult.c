/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:41:29 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 11:02:02 by mosriji          ###   ########.fr       */
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

int mini_atoi(char *str)
{
    int i;
    int res;
    int signe;

    i = 0;
    res = 0;
    signe = 1;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] -'0');
        i++;
    }
    return (signe * res);
}

void tab_mult(int nbr)
{
    int i;

    i = 0;
    while (i <= 9)
    {
        mini_putnbr(i);
        write(1, " x ", 3);
        mini_putnbr(nbr);
        write(1, " = ", 3);
        mini_putnbr(i*nbr);
        i++;
        write(1, "\n", 1);
    }
}

int main(int ac, char *av[])
{
    if (ac == 2)
    {
        tab_mult(mini_atoi(av[1]));
    }
    return (0);
}