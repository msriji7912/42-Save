/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:17:32 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:08:47 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;

    i = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            j = 0;
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                while (j < av[1][i] - 64)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                while (j < av[1][i] - 96)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}