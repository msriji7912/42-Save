/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 13:34:44 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/07 20:02:50 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*tmp_head;
	t_list	*final_head;
	t_list	*tmp_last;

	tmp_head = *stack;
	tmp_last = *stack;
	final_head = (*stack)->next;
	while (tmp_last->next != NULL)
		tmp_last = tmp_last->next;
	tmp_last->next = tmp_head;
	tmp_head->next = NULL;
	*stack = final_head;
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rotate_rotate(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
