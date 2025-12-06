/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 21:12:32 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 13:02:22 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	root -> content = content;
	root -> next = NULL;
	return (root);
}
/*
int	main(void)
{
    t_list	*node;
    char	*str = "Hello";

    node = ft_lstnew(str);
    printf ("%s\n", (char *)node->content);
    free(node);
    return (0);
}
*/