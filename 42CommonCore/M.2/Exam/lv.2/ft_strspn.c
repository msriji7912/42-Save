/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:55:34 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 12:09:09 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
    int i;
    int j;
    int check;

    i = 0;
    while (s[i])
    {
        j = 0;
        check = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
                check = 1;
            j++;
        }
        if (check == 0)
                return (i);
        i++;
    }
    return(i);
}

int main(void)
{
    const char *s = "haha...";
    const char *accept = "haha!";
    printf("result:%zu", ft_strspn(s, accept));
    return (0);
}