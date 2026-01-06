/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:54:33 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 12:09:43 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void str_cap(char *str)
{
    int i;
    int wrd;

    i = 0;
    wrd = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    wrd = i;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        else if ((str[i] >= 'a' && str[i] <= 'z') && (str[i-1] == ' ' || str[i-1] == '\t'))
            str[i] -= 32;
        if (str[wrd] >= 'a' && str[wrd] <= 'z')
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
        while (i < ac)
        {
            str_cap(av[i]);
            i++;
        }
    }
    return (0);
}