/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_moving.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:15 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/07 18:58:02 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack_a)
{
	t_list	*current;
	t_list	*after_current;

	current = stack_a;
	after_current = stack_a->next;
	while (after_current != NULL)
	{
		if (current->index > after_current->index)
			return (0);
		current = current->next;
		after_current = after_current->next;
	}
	return (1);
}

t_list	*find_min_stack(t_list *stack_a)
{
	t_list	*tmp_min;
	t_list	*forward;

	tmp_min = NULL;
	forward = stack_a;
	while (forward != NULL)
	{
		if (tmp_min == NULL)
			tmp_min = forward;
		else if (forward->index < tmp_min->index)
			tmp_min = forward;
		forward = forward->next;
	}
	return (tmp_min);
}

void	min_to_top_4(t_list **stack_a)
{
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*min;

	min = find_min_stack(*stack_a);
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	fourth = (*stack_a)->next->next->next;
	if (min == second)
		swap_a(*stack_a);
	else if (min == third)
	{
		reverse_a(stack_a);
		reverse_a(stack_a);
	}
	else if (min == fourth)
		reverse_a(stack_a);
}

void	min_to_top_5(t_list **stack_a)
{
	t_list	*min;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*fifth;

	min = find_min_stack(*stack_a);
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	fourth = (*stack_a)->next->next->next;
	fifth = (*stack_a)->next->next->next->next;
	if (min == second)
		swap_a(*stack_a);
	else if (min == third)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (min == fourth)
	{
		reverse_a(stack_a);
		reverse_a(stack_a);
	}
	else if (min == fifth)
		reverse_a(stack_a);
}
