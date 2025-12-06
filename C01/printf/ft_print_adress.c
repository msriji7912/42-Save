/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 01:09:40 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 06:42:14 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_adress(void *ptrr)
{
	size_t			i;
	uintptr_t		ptr;

	i = 0;
	ptr = (uintptr_t)ptrr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	ft_print_str("0x");
	i += 2;
	i += ft_hexa_ptr(ptr);
	return (i);
}
