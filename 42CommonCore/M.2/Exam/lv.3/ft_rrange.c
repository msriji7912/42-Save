/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:08:49 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:55:18 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     *ft_rrange(int start, int end)
{
    int i;
    int *wrdb;

    i = 0;
    if (start == end)
        return (0);
    else if (end > start)
    {
        wrdb = malloc(sizeof(int) * (end - start) + 1);
        if (!wrdb)
            return (0);
        while (end >= start)
        {
            wrdb[i] = end;
            i++;
            end--;
        }
    }
    else if (end < start)
    {
        wrdb = malloc(sizeof(int) * (start - end) + 1);
        if (!wrdb)
            return (0);
        while (start >= end)
        {
            wrdb[i] = end;
            i++;
            end++;
        }
    }
    return (wrdb); //when you return an array, you're actually,
    //returning a pointer to the first element
}

int main(void)
{
    int i;
    int size;
    int start = 15;
    int end = -7;
    int *tab = ft_rrange(start, end);

    i = 0;
    if (end > start)
        size = end - start;
    else if (start > end)
        size = start - end;
    else
        return (0);
    while (i < size)
    {
        printf("%d\n", tab[i]);
        i++;
    }
    return (0);
}
