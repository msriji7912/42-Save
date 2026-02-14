/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:37:08 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/10 13:34:02 by mosriji          ###   ########.fr       */
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
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
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
		else if (size > 5)
			radix_sort(stack_a, stack_b);
	}
}

int	checkings(int ac, char *av[])
{
	int	w;

	w = 1;
	if (ac < 2)
		return (1);
	while (av[w])
	{
		if (if_is_only_space(av[w]))
			return (error_msg(), 1);
		w++;
	}
	return (0);
}

int	main(int ac, char *av[])
{
	char	**tab;
	t_list	**stack_a;
	t_list	**stack_b;

	if (checkings(ac, av))
		return (1);
	stack_a = malloc(sizeof(t_list *));
	stack_b = malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
		return (free(stack_a), free(stack_b), 1);
	*stack_a = NULL;
	*stack_b = NULL;
	tab = prep_stack(ac, av);
	if (!tab)
		return (free(stack_a), free(stack_b), 1);
	*stack_a = parsing(tab);
	if (!*stack_a)
		return (free(stack_a), free(stack_b), 1);
	pick_algo(stack_a, stack_b);
	free_stack(*stack_a);
	free_stack(*stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}

/*
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
*/