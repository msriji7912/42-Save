/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:25:56 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 13:41:51 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **pushed, t_list **dest)
{
	t_list	*pushed_first;
	t_list	*pushed_second;

	pushed_second = (*pushed)->next;
	pushed_first = *pushed;
	pushed_first->next = *dest;
	*dest = pushed_first;
	*pushed = pushed_second;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pa");
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pb");
}
