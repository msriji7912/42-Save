/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:31:19 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 13:04:37 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		++counter;
		lst = lst -> next;
	}
	return (counter);
}
/*
int main(void)
{
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;
    
    node1 = ft_lstnew("Premier");
    node2 = ft_lstnew("Deuxieme");
    node3 = ft_lstnew("Troisieme");
    
    node1->next = node2;
    node2->next = node3;
    
    printf("Taille de la liste: %d\n", ft_lstsize(node1));
    
    free(node1);
    free(node2);
    free(node3);
    return (0);
}
*/