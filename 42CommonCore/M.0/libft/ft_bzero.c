/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 23:35:02 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 11:27:49 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*tmp_ptr;
	size_t		i;

	i = 0;
	tmp_ptr = (char *) s;
	while (i < n)
	{
		tmp_ptr[i] = 0;
		i++;
	}
}
/*
int main(void)
{
	char str[] = "je veux dormir";

	ft_bzero((char *)str, 4);
	printf("bzero: %s", str);
	return (0);
}
*/