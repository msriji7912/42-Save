/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 14:20:18 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:30:56 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		max(int* tab, unsigned int len)
{
    int max;
    unsigned int i;

    i = 0;
    if (len == 0 || !tab)
        return (0);
    max = tab[i];
    while (i <= len)
    {
        if (tab[i+1] > max)
            max = tab[i+1];
        i++;
    }
    return (max);
}

int main(void)
{
    int tab[7] = {3, 6, 84, 999, 7912, 4, 9999};
    printf("%d", max(tab, 7));
    return (0);
}
