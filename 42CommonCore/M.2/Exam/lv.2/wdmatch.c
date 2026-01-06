/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:57:24 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/30 14:02:01 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = 0;
    if (ac == 3)
    {
        while (av[1][len])
            len++;
        while (i < len && av[2][j])
        {
            if (av[1][i] == av[2][j])
                i++;
            j++;
            if (i == len)
                write(1, av[1], 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}