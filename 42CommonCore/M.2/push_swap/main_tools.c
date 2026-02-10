/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:54:23 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/10 11:55:07 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack_a)
{
	t_list	*current;

	if (!stack_a)
		return ;
	current = stack_a;
	while (stack_a)
	{
		current = stack_a->next;
		free(stack_a);
		stack_a = current;
	}
}

int	if_is_only_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}