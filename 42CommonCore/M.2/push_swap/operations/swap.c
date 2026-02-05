/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:44:22 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/04 14:43:58 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *stack)
{
	int		hold;
	t_list	*tmp;

	tmp = stack->next;
	hold = tmp->content;
	tmp->content = stack->content;
	stack->content = hold;
}

void	swap_a(t_list *stack_a)
{
	swap (stack_a);
}

void	swap_b(t_list *stack_b)
{
	swap (stack_b);
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	swap (stack_a);
	swap (stack_b);
}
