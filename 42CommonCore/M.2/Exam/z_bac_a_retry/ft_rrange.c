/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 07:56:06 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 08:04:11 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     *ft_rrange(int start, int end)
{
    int i;
    int *wrdb = NULL;

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
            end--;
            i++;
        }
    }
    else if (start > end)
    {
        wrdb = malloc(sizeof(int) * (start - end) + 1);
        if (!wrdb)
            return (0);
        while (start >= end)
        {
            wrdb[i] = end;
            end++;
            i++;
        }
    }
    return (wrdb);
}

int main(void)
{
    int i = 0;
    int start = 2;
    int end = -9;

    int *result = ft_rrange(start, end);
    int size;
    
    
    if (start > end)
        size = start - end + 1;
    else
        size = end - start + 1;
    
    while (i < size)
    {
        printf("%d ", result[i]);
        i++;
    }
    free(result);
    return (0);
}