/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 01:13:06 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/23 01:19:32 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void error_mess(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
