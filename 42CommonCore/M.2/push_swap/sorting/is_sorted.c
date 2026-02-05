/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:25:15 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 13:34:41 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted (t_list *stack_a, int size)
{
	int i;
	t_list *current;
	t_list *after_current;

	i = 0;
	current = stack_a;
	after_current = stack_a->next;
	while (i < size)
	{
		if (current->index > after_current->index)
			return (0);
		i++;
		current = current->next;
		after_current = after_current->next;
	}
	return (1);
}
