/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 14:47:22 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/03 14:54:56 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void str_cap (char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if ((str[i-1] == ' ' || str[i- 1] == '\t') && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        else if (str[0] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char *av[])
{
    int i;

    i = 1;
    if (ac == 1)
        write(1, "\n", 1);
    else 
    {
        if (i < ac)
            str_cap(av[i]);
        i++;
    }
    return (0);
}