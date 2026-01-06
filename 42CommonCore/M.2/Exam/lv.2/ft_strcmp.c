/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:08:22 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/30 08:04:05 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int    ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    if (!s1 || !s2)
        return(0);
    while (s1[i] || s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}

int main(void)
{
    char *s1 = NULL;
    char *s2 = "";
    printf("%d", ft_strcmp(s1, s2));
    return (0);
}