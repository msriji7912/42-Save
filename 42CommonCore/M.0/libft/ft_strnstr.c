/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 05:47:50 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/19 14:48:52 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find && (i + j) < len)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	str[15] = "Ecole";
	const char	*to_find;
	size_t		len;

	len = 3;
	to_find = "ol";
	printf ("%s", ft_strnstr(str, to_find, len));
	return (0);
}
*/