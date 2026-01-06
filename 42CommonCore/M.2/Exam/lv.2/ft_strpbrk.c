/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 12:17:22 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 12:25:53 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while(s2[j])
        {
            if (s1[i] == s2[j])
                return((char *)&s1[i]);
            j++;
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    const char *s1 = "hehe Enfinnn";
    const char *s2 = "! ";
    printf("results:%s", ft_strpbrk(s1, s2));
    return(0);
}