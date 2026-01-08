/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:43:53 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:02:03 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int word_count(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;
        if (str[i] && str[i] != c)
        {
            count++;
            while (str[i] && str[i] != c)
                i++;
        }
    }
    return (count);
}

int word_len(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    return (i);
}

void free_tab(char **tab)
{
    int i;

    i = 0;
    while(tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab); //don't forget to free the whole tab at the end
}

char **split(char *str, char c)
{
    int i;
    int j;
    int x;
    int words;
    char **tab;

    i = 0;
    j = 0;
    x = 0;
    words = word_count(str, c);
    tab = malloc (sizeof(char *) * words + 1);  // char etoile bc we are allocating tabs
    if (!tab)
        return (NULL);
    while (i < words) // meh first condition
    {
        j = 0; // (moved it up)
        while (str[x] && str[x] == c) // forgot this !!
            x++;
        tab[i] = malloc (sizeof(char) * word_len(str, c) + 1);
        if (!tab)
            free_tab(tab);
        while (str[x] && str[x] != c) // j < word_len(str, c)
        {
            tab[i][j] = str[x];
            j++;
            x++;
        }
        tab[i][j] = '\0'; //end the sentence!
        i++;
    }
    tab[i] = NULL; // don't forget this!!
    return (tab);
}

int main (void)
{
    size_t	i = 0;
	char	**tab;
	size_t	c = ' ';
	char	*str = "    mama   mia";

	tab = split(str, c);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	free_tab(tab);
	return (0);
}