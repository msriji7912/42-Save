/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:33:26 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/02 17:45:35 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>


int main(int ac, char *av[])
{
    int i;

    i = 0;
    if (ac < 2)
        return (0);
    if (ac >= 2)
    {
        if (ac == 2)
        {
            //split my av[2]
        }
        if (ac > 2)
        {
            
        } 
    }
}
// case with only one argument

// case where there are only 2 arguments

// case where I have multiple arguments

int valid_nbr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'a' && str[i] <= 'z'))
            return (1);
        i++;
    }
    return (0);
}

int dup_check(int ac, char *av[])
{
    int i;
    char *tmp;

    i = 0;
    if (ac > 2)
    {
        while (i < ac)
        {
            if ()
        }
    }
}