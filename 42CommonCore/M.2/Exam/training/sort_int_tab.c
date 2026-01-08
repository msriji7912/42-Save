/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:57:47 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 11:34:02 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int tmp;
    unsigned int i;
    unsigned int j;

    i = 0;
    j = 0;
    if (!tab || (size == 0))
        return;
    while (i < size - 1)
    {
        j = i;
        while (j < size)
        {
            if (tab[i] > tab[j])
            {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

int main (void)
{
    int i = 0;
    int size = 7;
    int tab[7] = {2, 14, 24, 7, 9, 45, 12};

    sort_int_tab(tab, size);
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}