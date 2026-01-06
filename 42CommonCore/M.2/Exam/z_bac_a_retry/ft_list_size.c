/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:23:10 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/04 16:30:42 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
    int i;
    
    i = 0;
    while (begin_list != NULL)
    {
        begin_list = begin_list->next;
        i++;
    }
    return (i);
}

t_list *new_list(void *content)
{
    t_list *root;

    root = malloc (sizeof(t_list));
    if (!root)
        return (NULL);
    root -> data = content;
    root -> next = NULL;
    return(root);
}

int main(void)
{
    int i = 0;
    char *str = "mona est ko";
    t_list *current;
    t_list *first;
    t_list *tmp;
    
    first = new_list(str);
    current = first;
    while (i < 7)
    {
        current -> next = new_list(str);
        current = current->next;
        i++;
    }
    printf("%s", (char *)current->data);
    while(first)
    {
        tmp = first->next;
        free(first);
        first = tmp;    
    }
    return (0);   
}
