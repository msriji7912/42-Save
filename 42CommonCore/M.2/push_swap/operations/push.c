/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:25:56 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/07 09:01:13 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **pushed, t_list **dest)
{
	t_list	*pushed_first;
	t_list	*pushed_second;

	if (!pushed || !*pushed)
		return ;
	pushed_second = (*pushed)->next;
	pushed_first = *pushed;
	pushed_first->next = *dest;
	*dest = pushed_first;
	*pushed = pushed_second;
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

/*
void	lst_add_front(t_list **stack , t_list *added)
{
	if (!stack || !added)
		return (1);
	added->next = *stack;
	*stack = added;
}
*/