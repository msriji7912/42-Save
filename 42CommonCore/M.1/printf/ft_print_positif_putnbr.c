/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_positif_putnbr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 07:22:51 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 01:50:31 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_positf_putnbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_print_positf_putnbr(nbr / 10);
	}
	i += ft_print_char((nbr % 10) + '0');
	return (i);
}
