/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:17:35 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 09:24:25 by mosriji          ###   ########.fr       */
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
    while (i <= len) // ou str[i]
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        i++;
        len--;
    }
    return(str);
}

int main(void)
{
    char str[] = "help";
    printf("%s", ft_strrev(str));
    return (0);
}