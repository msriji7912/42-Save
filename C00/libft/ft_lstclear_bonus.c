/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:33:59 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 14:48:00 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current;
		current = current -> next;
		del (tmp -> content);
		free (tmp);
	}
	*lst = NULL;
}
/*
int main(void)
{
    t_list *lst = NULL;
	

    t_list *a = ft_lstnew(malloc(10));
    t_list *b = ft_lstnew(malloc(20));
    t_list *c = ft_lstnew(malloc(30));

    a->next = b;
    b->next = c;
    lst = a;

    ft_lstclear(&lst, del_content);

    if (lst == NULL)
        printf("Liste correctement nettoyée !\n");
    else
        printf("Erreur : liste non vide.\n");
    return 0;
}
*/