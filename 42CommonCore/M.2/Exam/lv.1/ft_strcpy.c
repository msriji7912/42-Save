/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:06:42 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 08:11:39 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

// dest src
char *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    // s1[i] = 0;
    return (s1);
}

int main(void)
{
    char s1[100];
    char *s2 = "tired";
    printf("cpy:%s", ft_strcpy(s1, s2));
    return (0);
}