/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:13:11 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 14:04:22 by mosriji          ###   ########.fr       */
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
    free(tab);
}

char **ft_split(char *str, char c)
{
    int i = 0;
    int j = 0;
    int x = 0;
    int words;
    char **tab;

    words = word_count(str, c);
    tab = malloc(sizeof(char *) * words + 1);
    if (!tab)
        return (NULL);
    while(i < words)
    {
        while (str[x] && str[x] == c)
            x++;
        tab[i] = malloc (sizeof(char) * word_len(str, c) + 1);
        if (!tab)
            free_tab(tab);
        j = 0;
        while (str[x] && str[x] != c) // using the right condition
        {
            tab[i][j] = str[x];
            j++;
            x++;
        }
        tab[i][j] = '\0';
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

int main(void)
{
    int i = 0;
    char c = ' ';
    char *str = "mama mia";
    char **tab = ft_split(str, c);

    while (tab[i])
    {
        printf("%s\n", tab[i]); // use the /n at the end !!
        i++;
    }
    return (0);
}