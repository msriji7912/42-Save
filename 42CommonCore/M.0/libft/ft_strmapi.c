/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:51:02 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/20 19:41:26 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (!str || !f)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char	test_func(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("hello world", test_func);
	printf("%s\n", result);
	free(result);
	return (0);
}
*/