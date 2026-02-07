/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_supposed_product.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:59:55 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/07 11:50:45 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(int size)
{
    int bits;
    
    bits = 0;
    while ((size - 1) >> bits)
        bits++;
    return (bits);
}

void sort_by_bit(t_list **stack_a, t_list **stack_b, int bit_index)
{
    int size;
    int i;
    
    size = lst_size(*stack_a);
    i = 0;
    while (i < size)
    {
        if ((((*stack_a)->index >> bit_index) & 1) == 0)
            push_b(stack_a, stack_b);
        else
            rotate_a(stack_a);
        i++;
    }
    while (*stack_b)
        push_a(stack_b, stack_a);
}

void radix_sort(t_list **stack_a, t_list **stack_b)
{
    int max_bits;
    int i;
    
    max_bits = get_max_bits(lst_size(*stack_a));
    i = 0;
    while (i < max_bits)
    {
        sort_by_bit(stack_a, stack_b, i);
        i++;
    }
}