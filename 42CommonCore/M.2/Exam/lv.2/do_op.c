/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 09:41:29 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 09:49:04 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int i;

    i = 0;
    if (ac == 4)
    {
        if (av[2][0] == '+')
            printf("Addition:%d", atoi(av[1]) + atoi(av[3]));
        else if (av[2][0] == '-')
            printf("Soustraction:%d", atoi(av[1]) - atoi(av[3]));
        else if (av[2][0] == '*')
            printf("Multiplication:%d", atoi(av[1]) * atoi(av[3]));
        else if (av[2][0] == '/')
            printf("Divisiom:%d", atoi(av[1]) / atoi(av[3]));
        else if (av[2][0] == '%')
            printf("Modulo:%d", atoi(av[1]) % atoi(av[3]));
        else
            write(1, &av[1][i], 1);
    }
    printf("\n");
    return (0);
}