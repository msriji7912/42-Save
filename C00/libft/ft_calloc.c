/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 05:53:53 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/21 01:51:39 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*safe;
	size_t			len;
	size_t			i;

	i = 0;
	len = count * size;
	safe = malloc(len);
	if (!safe)
		return (NULL);
	while (i < len)
		safe[i++] = 0;
	return (safe);
}
/*
int	main(void)
{
	size_t	count;
	size_t	size;
	char	*safe;

	count = 4;
	size = 2;
	safe = ft_calloc(count, size);
	printf ("%s", safe);
	free (safe);
	return (0);
}
*/