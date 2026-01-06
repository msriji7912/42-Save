/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:17:18 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 11:22:24 by mosriji          ###   ########.fr       */
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
    while (nbr > 9)
        mini_putnbr(nbr / 10);
    mini_putchar((nbr % 10) + '0');
}
int main(int ac, char *av[])
{
    int i;

    i = 0;
    (void)av;
    if (ac == 1)
        return (write(1, "\n", 1), 0);
    else
        mini_putnbr(ac - 1);
    return (0);
}