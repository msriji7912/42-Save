/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:24:39 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 11:29:38 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void unionn(char *s1, char *s2)
{
    int i;
    char tab[256] = {0};

    i = 0;
    while (s1[i])
    {
        write(1, &s1[i], 1);
        tab[(int)s1[i]] = 1;
        i++;
    }
    i = 0;
    while (s2[i])
    {
        if (tab[(int)s2[i]] == 0)
        {
            write(1, &s2[i], 1);
            tab[(int)s2[i]] = 1;
        }
        i++;
    }
}

int main(int ac, char *av[])
{
    int i;

    i = 0;
    if (ac == 3)
        unionn(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}