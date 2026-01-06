/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 00:58:41 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/31 10:05:20 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

static int	count_words(const char	*str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (words);
}

static int	word_len(const char	*str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return ;
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	words = count_words(str, c);
	tab = malloc (sizeof(char *) * (words + 1));
	if (!tab)
		return (NULL);
	while (i < words)
	{
		j = 0;
		while (*str && *str == c)
			str++;
		tab[i] = malloc (sizeof(char) * word_len(str, c) + 1);
		if (!tab[i])
			return (free_tab(tab), NULL);
		while (*str && *str != c)
			tab[i][j++] = *str++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*
int main (void)
{
	char	**tab;
	char	*str;
	size_t	i;
	size_t	c;

	c = ' ';
	i = 0;
	str = "      ";
	tab = ft_split(str, c);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_tab(tab);
	return (0);
}
*/