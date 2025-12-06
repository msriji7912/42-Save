/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:02:59 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/12 00:33:58 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	uc;

	str = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char str[] = "Hello, World!";
 	int rechercher;
    size_t	n;

	n = 4;
    rechercher = 'd';
	printf("Chaîne : %s\n", str);
	printf("%s\n", (char *)ft_memchr(str, rechercher, n));
	printf("Chaîne : %s\n", str);
	printf("%s\n", (char *)memchr(str, rechercher, n));
    return (0);
}
*/
