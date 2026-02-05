/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:30:32 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 13:49:59 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *is_two(t_list *stack_a)
{
	swap_a(stack_a);
	return(stack_a);
}

t_list *is_three(t_list *stack_a)
{
    t_list *first;
	t_list *second;
	t_list *third;
	
	first = stack_a;
	second = stack_a->next; 
	third = stack_a->next->next;
	if (!is_sorted(stack_a))
	{
		
	}
}

t_list *is_four(t_list *stack_a)
{
    
}

t_list *is_five(t_list *stack_a)
{
    
}
