/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:53:40 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/27 23:31:30 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(long nbr)
{
	char	*base;
	int		i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 15)
		i += ft_print_hexa(nbr / 16);
	i += ft_print_char(base[nbr % 16]);
	return (i);
}
