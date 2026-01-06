/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:38:58 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/05 11:41:20 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
    int x;

    x = *a;
    *a = *b;
    *b = x;
}

int main(void)
{
    int a = 7;
    int b = 12;
    ft_swap(&a, &b);
    printf("a:%d, b:%d", a, b);
    return (0);
}