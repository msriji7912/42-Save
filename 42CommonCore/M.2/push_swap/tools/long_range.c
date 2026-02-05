/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_range.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:00:28 by mosriji           #+#    #+#             */
/*   Updated: 2026/02/05 11:11:51 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atol(const char *str)
{
	int		i;
	int		signe;
	long	res;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

int	is_range(long nbr)
{
	if (nbr > INT_MAX)
		return (1);
	else if (nbr < INT_MIN)
		return (1);
	else
		return (0);
}
