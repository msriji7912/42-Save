/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:08:58 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 11:16:29 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    char tmp;
    
    i = 0;
    len = 0;
    while (str[len])
        len++;
    len--;
    while (str[i])
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    return (str);
}

int main(void)
{
    char str[] = "mama mia";
    printf("%s", ft_strrev(str));
    return (0);
}