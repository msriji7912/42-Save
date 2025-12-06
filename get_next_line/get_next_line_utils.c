/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:31:04 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/02 11:18:05 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
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

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (&str[i]);
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
	char	*s1 = "mamKa";
	int		c = 'K';
	
	printf("%s", ft_strchr(s1, c));
	return(0);
}
*/