/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 08:23:33 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/16 08:37:39 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

long	search_n(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

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
	char	*str = "mamamia";
	
	printf("%s", ft_substr(str, 0, 4));
	return(0);
}
*/