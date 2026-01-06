/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:53:06 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 11:08:32 by mosriji          ###   ########.fr       */
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
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    return (dst);
}

int main(void)
{
    char *src = "mama mia";
    printf("%s", ft_strdup(src));
    return (0);
}