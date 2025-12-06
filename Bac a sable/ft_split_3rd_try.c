/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 07:34:06 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/15 09:53:59 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	count_word(const char *str, char c)
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


int	word_len(const char *str, char c)
{
	size_t	wrd;

	wrd = 0;
	while (str[wrd] && str[wrd] != c)
		wrd++;
	return(wrd);
}


void free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return;
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
		tab[i] = malloc(sizeof(char) * word_len(str, c) + 1);
		j = 0;
		while(*str && *str != c)
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