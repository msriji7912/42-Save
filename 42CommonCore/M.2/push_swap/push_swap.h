/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 14:45:38 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/04 19:55:57 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct t_list
{
	void			*content;
    int				index;
	struct t_list	*next;
}		t_list;

t_list	*new_node(int nbr);
void	lst_add_back(t_list **lst, t_list *to_add);
t_list	*stack_fill(int *tab, int size);


#endif