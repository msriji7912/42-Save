/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:20:18 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/30 12:20:48 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		max(int* tab, unsigned int len)
{
    unsigned int i;
    int max;

    i = 0;
    if (len == 0 || !tab)
        return (0);
    max = tab[i];
    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}

int main(void)
{
    int tab[6] = {-984, 4684, 10000, 2, -42, 900000};
    printf("hehe:%d", max(tab, 6));
    return(0);
}
