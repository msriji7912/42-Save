/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:05:04 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 13:11:29 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last -> next = new;
}
/*
int main(void)
{
    t_list *lst = NULL;

    t_list *a = ft_lstnew("Hello");
    t_list *b = ft_lstnew("World");
    t_list *c = ft_lstnew("42");

    ft_lstadd_back(&lst, a);
    ft_lstadd_back(&lst, b);
    ft_lstadd_back(&lst, c);

    t_list *tmp = lst;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;
    }
    return 0;
}
*/