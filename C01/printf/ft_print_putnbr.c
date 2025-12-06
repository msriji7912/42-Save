/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:22:51 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 00:57:02 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_putnbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 9)
	{
		i += ft_print_putnbr(nbr / 10);
	}
	i += ft_print_char((nbr % 10) + '0');
	return (i);
}
