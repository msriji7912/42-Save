/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:59:24 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/05 12:01:32 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int i;

    i = 0;
    if (ac == 4)
    {
        while (av[1][i])
        {
            if (av[1][i] == av[2][0])
                write(1, &av[3][0], 1);
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}