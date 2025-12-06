/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:53:40 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 06:38:19 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_ptr(uintptr_t nbr)
{
	char		*base;
	uintptr_t	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		i += ft_print_char('-');
	}
	if (nbr > 15)
		i += ft_hexa_ptr(nbr / 16);
	i += ft_print_char(base[nbr % 16]);
	return (i);
}
