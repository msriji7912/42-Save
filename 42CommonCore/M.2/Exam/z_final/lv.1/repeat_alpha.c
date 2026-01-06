/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:41:39 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/05 11:48:02 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                j = 0;
                while (j < av[1][i] - 96)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                j = 0;
                while (j < av[1][i] - 64)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}