/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:55:09 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 13:05:46 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
/*
int main(void)
{
	t_list *a = ft_lstnew("Premier");
	t_list *b = ft_lstnew("Deuxième");
	t_list *c = ft_lstnew("Troisième");

	a->next = b;
	b->next = c;

	t_list *last = ft_lstlast(a);

	if (last)
		printf("Dernier élément : %s\n", (char *)last->content);
	else
		printf("La liste est vide.\n");

	free(a);
	free(b);
	free(c);

	return 0;
}
*/