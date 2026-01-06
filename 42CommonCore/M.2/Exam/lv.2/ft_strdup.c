/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:43:27 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 10:52:17 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *ft_strdup(char *src)
{
    int i;
    int len;
    char *tmp;

    i = 0;
    len = 0;
    while (src[len])
        len++;
    tmp = malloc(sizeof(char) * len + 1);
    if (!tmp)
        return (NULL);
    while(src[i])
    {
        tmp[i] = src[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}

int main(void)
{
    char *src = "7912";
    printf("projet: %s", ft_strdup(src));
    return (0);
}