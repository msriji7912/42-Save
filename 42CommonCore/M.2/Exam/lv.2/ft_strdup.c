/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:43:27 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:20:52 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *ft_strdup(char *src)
{
    int i;
    int len;
    char *dst;

    i = 0;
    len = 0;
    while (src[len])
        len++;
    dst = malloc(sizeof(char) * len + 1);
    if (!dst)
        return (NULL);
    while(src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

int main(void)
{
    char *src = "7912";
    printf("projet: %s", ft_strdup(src));
    return (0);
}