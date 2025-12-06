/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:50:20 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 14:41:38 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
/*
void	print_content(void *content)
{
	printf ("%s\n", (char *)content);
}

int main(void)
{
    t_list *a = ft_lstnew("Hello");
    t_list *b = ft_lstnew("World");
    t_list *c = ft_lstnew("42");

    a->next = b;
    b->next = c;

    ft_lstiter(a, print_content);

    return 0;
}
*/