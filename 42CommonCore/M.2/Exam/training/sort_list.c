/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:14:43 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 12:25:10 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct    s_list
{
    struct s_list *next;
    int          data;
}                 t_list;


int ascending(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *current_1;
    t_list *current_2;
    int tmp;
    int res;
    
    current_1 = lst;
    current_2 = lst -> next;
    while (current_2 -> next != NULL) // the right cdt!!
    {
        res = cmp (current_1 -> data, current_2 -> data);
        if (res == 1)
        {
            current_1 = current_1->next;
            current_2 = current_2->next;
        }
        else if (res == 0)
        {
            tmp = current_1->data;
            current_1->data = current_2->data;
            current_2->data = tmp;

            current_1 = lst;
            current_2 = lst -> next;     // restart from beginning
        }
    }
    return (0);
}

int main(void)
{
    t_list *node_1 = NULL;
    t_list *node_2 = NULL;
    t_list *node_3 = NULL;

    node_1 = malloc (sizeof(t_list));
    node_2 = malloc (sizeof(t_list));
    node_3 = malloc (sizeof(t_list));
    
    node_1 -> data = 7;
    node_2 -> data = 2;
    node_3 -> data = 9;
    
    node_1 -> next = node_2;
    node_2 -> next = node_3;
    node_3 -> next = NULL;

    sort_list(node_1, ascending);
    printf("%d", node_1 -> data);
    printf("%d", node_2 -> data);
    printf("%d", node_3 -> data);

    return (0);
}