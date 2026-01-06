/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:40:41 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 08:55:23 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a program that displays the number of arguments passed to it, followed by a newline.

#include <stdio.h>
#include <unistd.h>

void mini_putchar(char c)
{
    write(1, &c, 1);
}

void mini_putnbr(int nbr)
{
    if (nbr > 9)
        mini_putnbr (nbr / 10);
    mini_putchar ((nbr % 10) + '0');
}

int main(int ac, char *av[])
{
    (void)av;
    mini_putnbr(ac - 1);
    write(1, "\n", 1);
    return (0);
}