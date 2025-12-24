/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:23:55 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/17 16:51:08 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	if (tmp_src < tmp_dst)
	{
		while (len-- > 0)
			tmp_dst[len] = tmp_src[len];
	}
	else
	{
		while (i < len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	}
	return (dst);
}
/*
int main(void)
{
    char str[20] = "Hello, World!";
	char str2[20] = "Worlz";
	
    ft_memmove(str, str2, 5);
    printf("Après  ft_memmove : %s\n\n", str);
    return (0);
}
*/