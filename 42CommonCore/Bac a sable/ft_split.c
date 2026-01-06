/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 09:27:50 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/16 10:20:08 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	count_word(const char *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while(str[i])
	{
		while(str[i] && str[i] == c)
			i++;
		if(str[i] && str[i] != c)
			words++;
		while(str[i] && str[i] != c)
			i++;
		//i++;
	}
	return (words);
}

int	word_len(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}


void	free_tab (char **tab)
{
	size_t	i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char **ft_split(char const *str, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	words;

	i = 0;
	words = count_word(str, c);
	tab = malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		while (*str && *str == c)
			str++;
		j = 0;
		tab[i] = malloc(sizeof(char) * word_len(str, c) + 1);
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
	const char *str = "Ye suis nul";
	char c = ' ';
	size_t	i;
	char **tab;
	
	i = -1;
	tab = ft_split(str, c);
	while (tab[++i])
		printf("%s\n", tab[i]);
	free_tab(tab);
	return (0);
}