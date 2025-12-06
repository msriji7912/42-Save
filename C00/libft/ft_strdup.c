/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 07:23:28 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/12 00:57:21 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dup = malloc (sizeof (char) * len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
/*
int	main(void)
{
	char	*s;
	char	*dup;

	s = "VON";
	dup = ft_strdup(s);
	printf ("%s", dup);
	free (dup);
	return (0);
}
*/