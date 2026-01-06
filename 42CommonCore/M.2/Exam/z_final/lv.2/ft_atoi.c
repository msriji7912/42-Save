/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 10:43:14 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/06 10:47:21 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
    int i;
    int res;
    int signe;

    i = 0;
    res = 0;
    signe = 1;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            signe *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] -'0');
        i++;
    }
    return (res * signe);
}

int main (void)
{
    const char *str = "7912";
    printf("%d", ft_atoi(str));
    return (0);
}