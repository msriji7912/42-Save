/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:33:35 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/05 11:36:12 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;
    
    i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    return(s1);
}

int main(void)
{
    char s1[100];
    char *s2 = "mama miiaaa";
    printf("%s", ft_strcpy(s1, s2));
    return (0);
}