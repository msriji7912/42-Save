/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:37:31 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 10:42:33 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int ac, char *av[])
{
    int i;

    i = 0;
    if (ac == 4)
    {
        if (av[2][0] == '+')
            printf("addition:%d", atoi(av[1]) + atoi(av[3]));
        else if (av[2][0] == '-')
            printf("soustraction:%d", atoi(av[1]) - atoi(av[3]));
        else if (av[2][0] == '*')
            printf("multiplication:%d", atoi(av[1]) * atoi(av[3]));
        else if (av[2][0] == '/')
            printf("division:%d", atoi(av[1]) / atoi(av[3]));
        else if (av[2][0] == '%')
            printf("modulo:%d", atoi(av[1]) % atoi(av[3]));
    }
    printf("\n");
    return (0);
}