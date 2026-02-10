/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_cases.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:30:32 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/10 11:32:43 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_two(t_list **stack_a)
{
	swap_a(*stack_a);
}

void	is_three(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*last;

	first = *stack_a;
	second = (*stack_a)->next;
	last = (*stack_a)->next->next;
	if (second->index > last->index && last->index > first->index)
	{
		reverse_a(stack_a);
		swap_a(*stack_a);
	}
	else if (second->index > first->index && first->index > last->index)
		reverse_a(stack_a);
	else if (last->index > first->index && first->index > second->index)
		swap_a(*stack_a);
	else if (first->index > second->index && second->index > last->index)
	{
		swap_a(*stack_a);
		reverse_a(stack_a);
	}
	else if (first->index > last->index && last->index > second->index)
		rotate_a(stack_a);
}

void	is_four(t_list **stack_a, t_list **stack_b)
{
	min_to_top_4(stack_a);
	push_b(stack_a, stack_b);
	assign_index(*stack_a);
	is_three(stack_a);
	push_a(stack_b, stack_a);
}

void	is_five(t_list **stack_a, t_list **stack_b)
{
	min_to_top_5(stack_a);
	push_b(stack_a, stack_b);
	assign_index(*stack_a);
	min_to_top_4(stack_a);
	push_b(stack_a, stack_b);
	assign_index(*stack_a);
	is_three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
