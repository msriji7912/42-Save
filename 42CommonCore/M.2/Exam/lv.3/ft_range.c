/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:12:15 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:54:11 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//ahhhhhh le main....
int     *ft_range(int start, int end)
{
    int i;
    int *wrdb = NULL;

    i = 0;
    if (start == end)
        return (0);
    else if (start < end)
    {
        wrdb = malloc(sizeof(int) * (end - start) + 1);
        if (!wrdb)
            return (0);
        while (start < end)
        {
            wrdb[i] = start;
            start++;
            i++;
        }
    }
    else if (end < start)
    {
        wrdb = malloc(sizeof(int) * (start - end) + 1);
        if (!wrdb)
            return (0);
        while (end < start)
        {
            wrdb[i] = start;
            start--;
            i++;
        }
    }
    return (wrdb);
}
int main(void)
{
    int i = 0;
    int start = 1;
    int end = 5;
    int *result = ft_range(start, end);
    int size = abs(end - start);
    
    while (i < size)
    {
        printf("%d ", result[i]);
        i++;
    }
    free(result);
    return (0);
}