/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 09:26:53 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/30 12:37:30 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int ac, char* av[])
{
    int i;

    i = 0;
    if (ac == 2)
    {
        while(av[1][i])
        {
            if(av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                write(1, "_", 1);
                av[1][i] -= 32;
                write(1, &av[1][i], 1);
            }
            else if(av[1][i] == ' ')
            {
                write(1, "_", 1);
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}