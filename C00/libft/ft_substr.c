/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 02:15:18 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/18 10:18:13 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlenght;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	strlenght = ft_strlen(s);
	if (start >= strlenght)
		return (ft_strdup(""));
	if (len > strlenght - start)
		len = strlenght - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len > 0 && start < strlenght)
	{
		str[i] = s[start];
		len--;
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char const	*s;
	char		*str;
	size_t		len;
	size_t		start;
	
	len = 2;
	s = "dodo";
	start = 3;
	str = ft_substr(s, start, len);
	printf("%s", str);
	free (str);
	return 0;
}
*/