/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:44:22 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/06 11:23:53 by mosriji          ###   ########.fr       */
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
	swap(stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_list *stack_b)
{
	swap(stack_b);
	ft_putstr("sb\n");
}

void	swap_both(t_list *stack_a, t_list *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putstr("ss\n");
}
