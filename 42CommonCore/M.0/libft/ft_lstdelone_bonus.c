/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:50:56 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 13:33:33 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst -> content);
	free(lst);
}

void	del_content(void *content)
{
	free(content);
}
/*
int main(void)
{
    t_list *node = malloc(sizeof(t_list));
    node->content = malloc(10);
    node->next = NULL;

    ft_lstdelone(node, del_content);

    printf("Node supprimé.\n");
    return 0;
}
*/