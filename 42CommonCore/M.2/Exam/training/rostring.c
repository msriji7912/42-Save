/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:49:27 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 10:05:22 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void rostring(char *str)
{
    int i;
    int flag;

    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    flag = i;
    while (str[i])
    {
        while (str[i] && str[i] != ' ' && str[i] != '\t') 
            i++;
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && (str[i-1] == ' ' || str[i-1] == '\t'))
        {
            while (str[i] && str[i] != ' ' && str[i] != '\t')
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
            i++;
        }
    }
    while (str[flag] && str[flag] != ' ' && str[flag] != '\t')
    {
        write(1, &str[flag], 1);
        flag++;
    }
}

int main(int ac, char *av[])
{
    int i;

    i = 1;
    if (ac >= 2)
    {
        rostring(av[i]);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
