/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:58:28 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 15:11:52 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct    s_list
{
    struct s_list *next;
    int          data;
}                 t_list;

int ft_list_size(t_list *begin_list)
{
    int i;

    i = 0;
	if (!begin_list)
		return (0);
    while (begin_list != NULL)
    {
        begin_list = begin_list -> next;
        i++;
    }
    return (i);
}

t_list *ft_new_list(void)
{
    t_list *root;
    
    root = malloc(sizeof(t_list));
    if (!root)
        return (NULL);
    root -> data = 7;
    root -> next = NULL;
    return (root);
}

t_list *ft_list_add_back(t_list *begin)
{
    t_list *current;

    current = begin;
    while (current->next != NULL)
        current = current -> next;
    current -> next = ft_new_list();
    return (begin);
}

int main(void)
{
    int i;
    t_list *begin;
    
    i = 0;
    begin = ft_new_list();
    while (i < 6)
    {
        ft_list_add_back(begin);
        i++;
    }
    printf("%d", ft_list_size(begin));
    return (0);
}