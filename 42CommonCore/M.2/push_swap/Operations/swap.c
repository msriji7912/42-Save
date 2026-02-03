/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:44:22 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/03 16:23:49 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_list **pushed, t_list **dest)
{
    t_list *pushed_first;
    t_list *pushed_second;

    pushed_second = (*pushed)->next; //take the second value of pushed
    pushed_first = *pushed; //take the first value of pushed
    pushed_first->next = *dest; //make the next of pushed being the dest
    *dest = pushed_first; //then dest takes pushedas it's head
    *pushed = pushed_second; //then pushed takes it;s second has it's head
}