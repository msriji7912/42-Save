/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:44:57 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/07 18:58:17 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int nbr)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = nbr;
	node->next = NULL;
	return (node);
}

void	lst_add_back(t_list **lst, t_list *to_add)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = to_add;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = to_add;
}

t_list	*stack_fill(int *tab, int size)
{
	int		i;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		lst_add_back(&stack_a, new_node(tab[i]));
		i++;
	}
	return (stack_a);
}
