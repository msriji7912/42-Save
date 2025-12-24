/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_up_hexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:53:40 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 01:14:28 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_up_hexa(long nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789ABCDEF";
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 15)
		i += ft_print_up_hexa(nbr / 16);
	i += ft_print_char(base[nbr % 16]);
	return (i);
}
