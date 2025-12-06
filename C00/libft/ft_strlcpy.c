/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:36:22 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 14:49:04 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (siz == 0)
		return (len);
	while (src[i] && i < (siz - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
/*
int	main(void)
{
	char	*dst;
	char	*src;
	char	len;
	size_t	siz;

	len = 0;
	dst = malloc(sizeof(char) * len + 1);
	src = "mama mia la pizza de la mama";
	siz = 7;
	printf ("%zu", ft_strlcpy(dst, src, siz));
	return (0);
}
*/
