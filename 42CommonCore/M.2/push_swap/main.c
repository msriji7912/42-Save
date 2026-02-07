/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:37:08 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/07 09:47:16 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack_a)
{
	t_list	*current;
	t_list	*previous;

	if (!stack_a)
		return ;
	current = stack_a;
	previous = stack_a;
	while (current != NULL)
	{
		current = current->next;
		free(previous);
		previous = current;
	}
}

void	print_list(t_list *stack_a)
{
	t_list	*current;

	current = stack_a;
	while (current != NULL)
	{
		printf("%d\n", current->content);
		current = current->next;
	}
}

void	pick_algo(t_list **stack_a, t_list **stack_b)
{
	int	size;

	assign_index(*stack_a);
	if (!is_sorted(*stack_a))
	{
		size = lst_size(*stack_a);
		if (size == 2)
			is_two(stack_a);
		else if (size == 3)
			is_three(stack_a);
		else if (size == 4)
			is_four(stack_a, stack_b);
		else if (size == 5)
			is_five(stack_a, stack_b);
		if (size > 3)
			free_stack(*stack_b);
	}
}

int	main(int ac, char *av[])
{
	char	**tab;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = malloc(sizeof(t_list **));
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(t_list **));
	if (!stack_b)
		return (1);
	if (ac < 2)
		return (0);
	tab = prep_stack(ac, av);
	if (!tab)
		return (1);
	*stack_a = parsing(tab);
	if (!*stack_a)
		return (free(stack_a), 1);
	pick_algo(stack_a, stack_b);
	// print_list(*stack_a);
	free_stack(*stack_a);
	free(stack_a);
	return (0);
}

// else
// boss_final_radix(stack_a, stack_b);