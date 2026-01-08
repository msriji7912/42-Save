/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:34:59 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 12:10:08 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    if (ac == 2)
    {
        while (av[1][i])
            i++;
        i--;
        while(i > 0)
        {
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i--;
            while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
                i--;
            flag = i;
            i++;
            while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
            {
                write(1, &av[1][i], 1);
                i++;
            }
            i = flag;
            if (i > 0)
                write(1, " ", 1);
        }
    }
    write(1, "\n", 1);
    return (0);
}
