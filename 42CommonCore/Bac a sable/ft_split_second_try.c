/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 01:03:49 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/15 04:55:06 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	count_word(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

int	world_len(char const *wrd, char c)
{
	size_t	len;

	len = 0;
	while (wrd[len] && wrd[len] != c)
		len++;
	return (len);
}

int	free_tab (char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	char	**tab;
	size_t	wrd_nbr;

	i = 0;
	wrd_nbr = count_word(str, c);
	tab = malloc(sizeof(char *) * (wrd_nbr + 1));
	if (!tab)
		return (NULL);
	while (i < wrd_nbr)
	{
		while (*str == c)
			str++;
		tab[i] = malloc(sizeof(char) * world_len(str, c) + 1);
		if (!tab[i])
			return (free_tab(tab), NULL);
		j = 0;
		while (*str && *str != c)
			tab[i][j++] = *str++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(void)
{
	char	c = ' ';
	char	*str;
	char **tab;
	int x = -1;
	
	str = "Ye suis nul";
	tab = ft_split(str, c);
	while (tab[++x])
		printf("%s\n", tab[x]);
	return (0);
}