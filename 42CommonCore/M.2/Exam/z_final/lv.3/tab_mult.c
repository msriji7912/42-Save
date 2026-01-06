/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:58:15 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 17:15:02 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void mini_putchar(char c)
{
    write(1, &c, 1);
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
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res * signe);
}

void mini_putnbr(int nbr)
{
    if (nbr > 9)
        mini_putnbr(nbr / 10);
    mini_putchar((nbr % 10) + '0');
}

int main(int ac, char *av[])
{
    int i;
    int nbr;

    i = 0;
    if (ac == 2)
    {
        nbr = mini_atoi(av[1]);
        while (i < 10)
        {
            mini_putnbr(i);
            write(1, " x ", 3);
            mini_putnbr(nbr);
            write(1, " = ", 3);
            mini_putnbr(i * nbr);
            i++;
            write(1, "\n", 1);
        } 
    }
    write(1, "\n", 1);
    return (0);
}