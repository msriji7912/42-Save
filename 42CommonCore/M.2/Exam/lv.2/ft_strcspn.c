/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:42:34 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/29 11:52:27 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i;
    int j;

    i = 0;
    while(s[i])
    {
        j = 0;
        while(reject[j])
        {
            if(s[i] == reject[j])
                return(i);
            j++;
        }
        i++;
    }
    return (i);
}

int main(void)
{
    const char *s = "haha..";
    const char *reject = ".!,";
    printf("results:%zu", ft_strcspn(s, reject));
    return (0);
}