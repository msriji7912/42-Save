/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 09:37:08 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 13:21:37 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack_a)
{
	t_list	*current;
	t_list	*previous;

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

int	main(int ac, char *av[])
{
	char	**tab;
	t_list	*stack_a;

	if (ac < 2)
		return (0);
	tab = prep_stack(ac, av);
	if (!tab)
		return (1);
	stack_a = parsing(tab);
	if (!stack_a)
		return (1);
	print_list(stack_a);
	free_stack(stack_a);
	return (0);
}

/*
int	main(int ac, char *av[])
{
	char	**tab;
	t_list	*stack_a;

	tab = NULL;
	tab = prep_stack(ac, av);
	stack_a = parsing(tab);
	print_list(stack_a);
	free_stack(stack_a);
	return (0);
}
*/