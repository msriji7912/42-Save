/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 06:12:36 by mosriji           #+#    #+#             */
/*   Updated: 2025/12/31 10:05:16 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

static int	count_nbr(size_t nbr)
{
	long	nbrs;
	size_t	count;

	count = 0;
	nbrs = nbr;
	if (nbrs < 0)
		count = 1;
	if (nbrs == 0)
		return (1);
	while (nbrs)
	{
		nbrs /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	count;
	char	*save;

	nbr = n;
	count = count_nbr(n);
	save = malloc(sizeof(char) * (count + 1));
	if (!save)
		return (NULL);
	save[count] = '\0';
	count --;
	if (nbr == 0)
		return (save[0] = '0', save);
	if (nbr < 0)
	{
		nbr *= -1;
		save[0] = '-';
	}
	while (nbr > 0)
	{
		save[count] = (nbr % 10) + '0';
		nbr /= 10;
		count--;
	}
	return (save);
}
/*
int	main(void)
{
	char	*save;
	long	nbr;

	nbr = 7912;
	save = ft_itoa(nbr);
	printf ("%s", save);
	free (save);
	return (0);
}
*/