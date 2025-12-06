/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 23:52:43 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/11 21:21:59 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	dstlen = 0;
	srclen = 0;
	while (dst[dstlen])
		dstlen++;
	while (src[srclen])
		srclen++;
	if (dstlen >= size)
		return (srclen + size);
	while ((dstlen + i < size - 1) && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int	main(void)
{
	const char *src;
	size_t	size;

	char dst[45] = "Ecole";
	src = "42";
	size = 8;
	printf("%zu", ft_strlcat(dst, src, size));
	return 0;
} 
*/