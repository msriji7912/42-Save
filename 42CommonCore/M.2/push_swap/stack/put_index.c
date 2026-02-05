/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:52:06 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 13:21:13 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// almost just the return wasn't right
void	initialize_index(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current != NULL)
	{
		current->index = -1;
		current = current->next;
	}
}

// check the -1
// compare with the forward

t_list	*min_finder(t_list *stack_a)
{
	t_list	*tmp_min;
	t_list	*forward;

	tmp_min = NULL;
	forward = stack_a;
	while (forward != NULL)
	{
		if (forward->index == -1)
		{
			if (tmp_min == NULL)
				tmp_min = forward;
			else if (forward->content < tmp_min->content)
				tmp_min = forward;
		}
		forward = forward->next;
	}
	return (tmp_min);
}

int	lst_size(t_list *stack_a)
{
	int		size;
	t_list	*current;

	size = 0;
	current = stack_a;
	while (current != NULL)
	{
		size++;
		current = current->next;
	}
	return (size);
}

// collect the min
// assign the index

void	assign_index(t_list *stack_a, int size)
{
	int		i;
	t_list	*actual_min;

	i = 0;
	while (i < size)
	{
		actual_min = min_finder(stack_a);
		actual_min->index = i;
		i++;
	}
}
