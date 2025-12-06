/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosriji <mosriji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 22:01:09 by mosriji           #+#    #+#             */
/*   Updated: 2025/11/28 16:44:07 by mosriji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_type(char type, va_list ap)
{
	size_t	count;

	count = 0;
	if (type == 'c')
		return (count += ft_print_char(va_arg(ap, int)));
	else if (type == 's')
		return (count += ft_print_str(va_arg(ap, char *)));
	else if (type == 'd' || type == 'i')
		return (count += ft_print_putnbr(va_arg(ap, int)));
	else if (type == 'p')
		return (count += ft_print_adress(va_arg(ap, void *)));
	else if (type == 'u')
		return (count += ft_print_positf_putnbr(va_arg(ap, unsigned int)));
	else if (type == 'x')
		return (count += ft_print_hexa(va_arg(ap, unsigned int)));
	else if (type == 'X')
		return (count += ft_print_up_hexa(va_arg(ap, unsigned int)));
	else
		return (count += ft_print_char(type));
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
			count += printf_type(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	//ft_printf("yay: %d\n", );
	ft_printf("%d", printf(NULL));
	printf("\n");
	printf("%d", printf(NULL));
	return (0);
}
*/