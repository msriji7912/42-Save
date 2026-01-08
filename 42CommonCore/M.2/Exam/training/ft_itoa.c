/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:24:24 by mosriji           #+#    #+#             */
/*   Updated: 2026/01/08 14:33:50 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int count_nbr(int n)
{
    long nbr = n;
    size_t	count;

    if (nbr == 0)
        return (1); // 1 et pas 0

    if (nbr < 0)
        count = 1;

    while (nbr)     // trust
    {
        nbr /= 10;   //abuse mdrr
        count++;
    }
    return (count);
}

char	*ft_itoa(int n)
{
    long	nbr = n;
	size_t	count;
	char	*save;

    count = count_nbr(nbr);
    save = malloc (sizeof(int) * count + 1);
    if (!save)
        return (NULL);
    save[count] = '\0';
    count--;                  //reculer apres !!
    
    if (nbr == 0)
    {
        save[0] = '0';
        return (save);         // must return
    }
    if (n < 0)
    {
        nbr *= -1;              // put it into a positive nbr
        save[0] = '-';
    }

    while (nbr > 0) // use nbr directly bro
	{
		save[count] = (nbr % 10) + '0'; //almost there learn from here
		nbr /= 10;
		count--;
	}
}

