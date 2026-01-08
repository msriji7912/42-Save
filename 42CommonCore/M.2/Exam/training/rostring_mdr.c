/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:17:31 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/07 16:37:19 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int rostring (char *str)
{
    int i;
    int flag;

    i = 0;
    while (str[i] && (str[i] == ' ' || str[i] == '\t')) 
        i++;
    flag = i;
    while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
    if (str[i] == '\0')
    {
        i = flag;
        while (str[i])
        {
            write(1, &str[i], 1);
            i++;
        }
        return (0);
    }
    while(str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t')) 
            i++;
        while (str[i] && str[i] != ' ' && str[i] != '\t') 
        {
            write(1, &str[i], 1);
            i++;
        }
        if (i > 0 && str[i])
        {
            write(1, " ", 1);
            i++;
        }
    }
    i = flag;
    write(1, " ", 1);
    while (str[i] != ' ' && str[i] != '\t')
    {
        write(1, &str[i], 1);
        i++;
    }
    return (0);
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