/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:41:03 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 13:02:59 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new -> next = *lst;
		*lst = new;
	}
}
/*
int main(void)
{
    t_list  *liste;
    t_list  *node;
    char    *str;
    
	liste = NULL;
	str = "Yesuisnul";
    node = ft_lstnew(str);
    ft_lstadd_front(&liste, node);
    
    printf("%s\n", (char *)liste->content);
    
    free(node);
    return (0);
}
*/