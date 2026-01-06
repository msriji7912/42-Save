/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:17:35 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 11:38:59 by mosriji          ###   ########.fr       */
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
    while (i < len - 1)
    {
        tmp = str[i];
        str[i] = str[len - 1];
        str[len - 1] = tmp;
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