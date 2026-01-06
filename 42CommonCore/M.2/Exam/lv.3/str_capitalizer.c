/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 15:22:52 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/01 18:10:18 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void str_cap(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i-1] == ' ' || str[i-1] == '\t'))
            str[i] -= 32;
        if (str[0] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main (int ac, char *av[])
{
    int i;

    i = 1;
    if (ac == 1)
        write(1, "\n", 1);
    while (i < ac)
    {
        str_cap(av[i]);
        i++;
    }
    return (0);
}