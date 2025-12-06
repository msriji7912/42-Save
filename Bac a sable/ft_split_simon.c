/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:58:41 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/14 06:04:38 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	count_words(const char	*str, char c)
{
	size_t	i;
	size_t	count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

int	word_len(const char	*str, char c)
{
	size_t	i;
	
	i = 0;
	while(str[i] != c && str[i])
		i++;
	return (i);
}
void	free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

char **ft_split(char const *str, char c)
{
	char **tab;
    int i;
	int j;
	int words;

	i = 0;
	words = count_words(str, c);
	tab = malloc (sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while(i <= words)
	{
		j = 0;
		tab[i] = malloc (sizeof(char) * word_len(str, c) + 1);
		if (!tab[i])
			return (free_tab(tab), NULL);
		while (*str && *str == c)
			str++;
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
	char **tab;
	char	*str;
	size_t	i;
	size_t	c;
	
	c = ' ';
	i = 0;
	str = "Je suis ko";
	tab = ft_split(str, c);
	while(tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_tab(tab);
	return 0;
}